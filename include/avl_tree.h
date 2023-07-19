#ifndef AVL_TREE_H
#define AVL_TREE_H

/*
 * Experimental implementation
 */

#include "symbol.h"

typedef struct avl_node
{
  symbol_t *value;
  struct avl_node *parent;
  struct avl_node *left;        /* minor */
  struct avl_node *right;       /* major */
} avl_node_t;

avl_node_t *avl_create (symbol_t * value);
avl_node_t *avl_search (avl_node_t * tree, const char *name);
void avl_destroy (avl_node_t * tree);
void avl_add (avl_node_t * tree, symbol_t * value);
avl_node_t *avl_add_create (avl_node_t * tree, symbol_t * value);

#endif
