#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "symbol.h"

typedef struct avl_node
{
  symbol_t *symbol;
  struct avl_node *parent;
  struct avl_node *left;        /* smaller than */
  struct avl_node *right;       /* greater than */
} avl_node_t;

avl_node_t *avl_create (symbol_t * sym);
symbol_t *avl_search (avl_node_t * tree, const char *str);
void avl_destroy (avl_node_t * node);
void avl_add (avl_node_t * tree, symbol_t * sym);

#endif
