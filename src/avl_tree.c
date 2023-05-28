#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void avl_add_in_left (avl_node_t * tree, symbol_t * value);
static void avl_add_in_right (avl_node_t * tree, symbol_t * value);
static void avl_rebalance (avl_node_t * tree);
static int avl_get_height (avl_node_t * tree);
static void avl_rotate (avl_node_t * tree, int left, int right);

avl_node_t *
avl_create (symbol_t * value)
{
  assert (value != NULL);
  assert (value->name != NULL);

  avl_node_t *tree = calloc (1, sizeof (avl_node_t));
  assert (tree != NULL);
  tree->value = value;

  return tree;
}

avl_node_t *
avl_search (avl_node_t * tree, const char *name)
{
  assert (tree != NULL);
  assert (name != NULL);

  int v = strcmp (name, tree->value->name);
  if (v == 0)
    return tree;
  if (v < 0 && tree->left != NULL)
    return avl_search (tree->left, name);
  else if (v > 0 && tree->right != NULL)
    return avl_search (tree->right, name);
  else
    return NULL;
}

void
avl_destroy (avl_node_t * tree)
{
  assert (tree != NULL);

  if (tree->left != NULL)
    avl_destroy (tree->left);
  if (tree->right != NULL)
    avl_destroy (tree->right);
  free (tree);
}

void
avl_add (avl_node_t * tree, symbol_t * value)
{
  assert (tree != NULL);
  assert (value != NULL);
  assert (value->name != NULL);

  int v = strcmp (tree->value->name, value->name);
  if (v == 0)
    return;

  if (v < 0 && tree->left == NULL)
    avl_add_in_left (tree, value);
  else if (v > 0 && tree->right == NULL)
    avl_add_in_right (tree, value);
  else if (v < 0 && tree->left != NULL)
    avl_add (tree->left, value);
  else if (v > 0 && tree->right != NULL)
    avl_add (tree->right, value);
}

static void
avl_add_in_left (avl_node_t * tree, symbol_t * value)
{
  assert (tree != NULL);
  assert (value != NULL);

  tree->left = calloc (1, sizeof (avl_node_t));
  assert (tree->left != NULL);
  tree->left->value = value;
  tree->left->parent = tree;
  avl_rebalance (tree);
}

static void
avl_add_in_right (avl_node_t * tree, symbol_t * value)
{
  assert (tree != NULL);
  assert (value != NULL);

  tree->right = calloc (1, sizeof (avl_node_t));
  assert (tree->right != NULL);
  tree->right->value = value;
  tree->right->parent = tree;
  avl_rebalance (tree);
}

static void
avl_rebalance (avl_node_t * tree)
{
  assert (tree != NULL);

  /*
   * A tree needs to be rebalanced when
   * the difference between the left height
   * and the right heigth is greater than 1.
   */

  int left = avl_get_height (tree->left);
  int right = avl_get_height (tree->right);
  int diff = (left > right) ? left - right : right - left;

  if (diff > 1)
    avl_rotate (tree, left, right);
  else if (tree->parent != NULL)
    avl_rebalance (tree->parent);
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
  return (left > right) ? left + 1 : right + 1;
}

static void
avl_rotate (avl_node_t * tree, int left, int right)
{
  assert (tree != NULL);
  assert (left != right);
  if (left > right)
    assert (left - right > 1);
  if (left < right)
    assert (right - left > 1);

  avl_node_t *A = tree;
  symbol_t *vA = A->value;

  if (tree->left == NULL && tree->right != NULL)
    {
      avl_node_t *B = A->right;
      symbol_t *vB = B->value;

      if (tree->right->left == NULL && tree->right->right != NULL)
        {
          avl_node_t *C = B->right;
          symbol_t *vC = C->value;
          C->parent = A;
          B->right = NULL;
          A->left = C;
          A->value = vB;
          B->value = vC;
          C->value = vA;
        }
      else if (tree->right->left != NULL && tree->right->right == NULL)
        {
          avl_node_t *C = B->left;
          symbol_t *vC = C->value;
          C->parent = A;
          B->left = NULL;
          A->left = C;
          A->value = vC;
          C->value = vA;
          /* B remains unchanged */
        }
    }
  else if (tree->left != NULL && tree->right == NULL)
    {
      avl_node_t *B = A->left;
      symbol_t *vB = B->value;

      if (tree->left->left != NULL && tree->left->right == NULL)
        {
          avl_node_t *C = B->left;
          symbol_t *vC = C->value;
          C->parent = A;
          B->left = NULL;
          A->right = C;
          A->value = vB;
          B->value = vC;
          C->value = vA;
        }
      else if (tree->left->left == NULL && tree->left->right != NULL)
        {
          avl_node_t *C = B->right;
          symbol_t *vC = C->value;
          C->parent = A;
          B->right = NULL;
          A->right = C;
          A->value = vC;
          C->value = vA;
          /* B remains unchanged */
        }
    }
}
