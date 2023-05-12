#ifndef INITIALIZER_T_H
#define INITIALIZER_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  INITZER_EXPR,
  INITZER_LIST
} initzer_kind_t;

typedef struct initzer
{
  initzer_kind_t kind;
  union
  {
    struct ass_expr *ass_expr;  /* INITZER_EXPR */
    struct
    {
      int n_initzer_block;
      struct initzer_block *initzer_blocks;
    } list;                     /* INITZER_LIST */
  };
  ast_node_t *node;
} initzer_t;

#endif
