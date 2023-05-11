#ifndef ADD_EXPR_T_H
#define ADD_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct add_expr
{
  struct mult_expr *right;
  struct add_expr *left;
  int op;
  ast_node_t *node;
} add_expr_t;

#endif
