#ifndef BLOCK_ITEM_T_H
#define BLOCK_ITEM_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  BLOCK_DECLARATION,
  BLOCK_STATEMENT
} block_kind_t;

typedef struct block_item
{
  block_kind_t kind;
  union
  {
    struct declaration *decl;
    struct statement *stmt;
  };
  ast_node_t *node;
} block_item_t;

#endif
