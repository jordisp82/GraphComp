#ifndef COMPOUND_STMT_T_H
#define COMPOUND_STMT_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct compound_stmt
{
  int n_block_items;
  struct block_item **block_items;
  ast_node_t *node;
} compound_stmt_t;

#endif
