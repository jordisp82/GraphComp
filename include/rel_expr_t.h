#ifndef REL_EXPR_T_H
#define REL_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct rel_expr
{
  struct shift_expr *right;
  struct rel_expr *left;
  int op;
  ast_node_t *node;
} rel_expr_t;

#endif
