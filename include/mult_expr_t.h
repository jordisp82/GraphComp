#ifndef MULT_EXPR_T_H
#define MULT_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct mult_expr
{
  struct cast_expr *right;
  struct mult_expr *left;
  int op;
  ast_node_t *node;
} mult_expr_t;

#endif
