#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "avl_tree.h"
#include "symbol.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

/*
 * https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
 */

static void avl_rebalance (avl_node_t * tree);
static void avl_rebalance_left (avl_node_t * tree);
static void avl_rebalance_right (avl_node_t * tree);
static int avl_get_height (avl_node_t * tree);
static void avl_rotate_left (avl_node_t * tree);
static void avl_rotate_right (avl_node_t * tree);

avl_node_t *
avl_create (symbol_t * sym)
{
  assert (sym != NULL);

  avl_node_t *tree = calloc (1, sizeof (avl_node_t));
  assert (tree != NULL);
  tree->symbol = sym;

  return tree;
}

symbol_t *
avl_search (avl_node_t * tree, const char *str)
{
  assert (tree != NULL);
  assert (str != NULL);

  int v = strcmp (str, tree->symbol->name);

  if (v == 0)
    return tree->symbol;
  else if (v < 0 && tree->left != NULL)
    return avl_search (tree->left, str);
  else if (v > 0 && tree->right != NULL)
    return avl_search (tree->right, str);
  else
    return NULL;
}

void
avl_destroy (avl_node_t * node)
{
  assert (node != NULL);

  if (node->left != NULL)
    avl_destroy (node->left);
  if (node->right != NULL)
    avl_destroy (node->right);
  /* NOTE do not free any of symbol's fields! */
  free (node->symbol);
  free (node);
}

int
avl_add (avl_node_t * tree, symbol_t * sym)
{
  assert (tree != NULL);
  assert (sym != NULL);
  assert (sym->name != NULL);

  /**
   * We traverse the tree, either left or right,
   * until we find a node where we can create
   * a child, either left or right.
   */

  avl_node_t *ptr = tree;

  while (1)
    {
      int v = strcmp (sym->name, ptr->symbol->name);
      if (v == 0)
        return -1;              /* the symbol is already on the tree */
      else if (v < 0)
        {
          if (ptr->left == NULL)
            {
              ptr->left = calloc (1, sizeof (avl_node_t));
              assert (ptr->left != NULL);
              ptr->left->symbol = sym;
              ptr->left->parent = ptr;
              avl_rebalance (ptr);
              return 0;
            }
          else
            ptr = ptr->left;
        }
      else if (v > 0)
        {
          if (ptr->right == NULL)
            {
              ptr->right = calloc (1, sizeof (avl_node_t));
              assert (ptr->right != NULL);
              ptr->right->symbol = sym;
              ptr->right->parent = ptr;
              avl_rebalance (ptr);
              return 0;
            }
          else
            ptr = ptr->right;
        }
    }
}

static void
avl_rebalance (avl_node_t * tree)
{
  assert (tree != NULL);

  avl_node_t *ptr = tree;
  int left = 0, right = 0;

  /**
   * Is there any imbalance? If not, no need to rebalance
   * what's already balanced.
   */

  while (abs (left - right) < 2)
    {
      left = avl_get_height (ptr->left);
      right = avl_get_height (ptr->right);
      if (abs (left - right) < 2)
        ptr = ptr->parent;
      if (ptr == NULL)
        return;
    }

#if 0
  for (ptr = tree; abs (left - right) < 2 && ptr != NULL; ptr = ptr->parent)
    {
      left = avl_get_height (ptr->left);
      right = avl_get_height (ptr->right);
    }
#endif

  if (abs (left - right) < 2)
    return;

  /**
   * Ok, there's an imbalance, and supposedly
   * we've found it as close as possible.
   */

  if (left < right)
    avl_rebalance_left (ptr);
  else if (left > right)
    avl_rebalance_right (ptr);

  /* no need to check whether left and right are equal */
}

static void
avl_rebalance_left (avl_node_t * tree)
{
  assert (tree != NULL);

  /* right-right or right-left? */
  int h_left = avl_get_height (tree->right->left);
  int h_right = avl_get_height (tree->right->right);

  if (h_right > h_left)         /* right-right */
    avl_rotate_left (tree);
  else if (h_right < h_left)    /* right-left */
    {
      avl_rotate_right (tree->right);
      avl_rotate_left (tree);
    }
  /* else: unreachable, in theory */
}

static void
avl_rebalance_right (avl_node_t * tree)
{
  assert (tree != NULL);

  /* left-left or left-right? */
  int h_left = avl_get_height (tree->left->left);
  int h_right = avl_get_height (tree->left->right);

  if (h_left > h_right)         /* left-left */
    avl_rotate_right (tree);
  else if (h_left < h_right)    /* left-right */
    {
      avl_rotate_left (tree->left);
      avl_rotate_right (tree);
    }
  /* else: unreachable, in theory */
}

static void
avl_rotate_left (avl_node_t * tree)
{
  assert (tree != NULL);

  symbol_t *sz = tree->symbol;
  symbol_t *sy = tree->right->symbol;
  symbol_t *sx = tree->right->right->symbol;

  tree->symbol = sy;
  tree->right->symbol = sx;
  avl_node_t *tmp = tree->right;
  tree->right = tree->right->right;
  tree->right->parent = tree;
  tmp->symbol = sz;
  tmp->right = tmp->left;
  tmp->left = tree->left;
  tree->left->parent = tmp;
  tree->left = tmp;
}

static void
avl_rotate_right (avl_node_t * tree)
{
  assert (tree != NULL);

  symbol_t *sz = tree->symbol;
  symbol_t *sy = tree->left->symbol;
  symbol_t *sx = tree->left->left->symbol;

  tree->symbol = sy;
  tree->left->symbol = sx;
  avl_node_t *tmp = tree->left;
  tree->left = tree->left->left;
  tree->left->parent = tree;
  tmp->symbol = sz;
  tmp->left = tmp->right;
  tmp->right = tree->right;
  tree->right->parent = tmp;
  tree->right = tmp;
}

static int
avl_get_height (avl_node_t * tree)
{
  if (tree == NULL)
    return 0;
  if (tree->left == NULL && tree->right == NULL)
    return 1;

  int left = avl_get_height (tree->left);
  int right = avl_get_height (tree->right);
  int max = (left > right) ? left : right;
  return max + 1;
}
