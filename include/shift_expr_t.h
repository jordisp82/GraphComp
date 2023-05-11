#ifndef SHIFT_EXPR_T_H
#define SHIFT_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct shift_expr
{
  struct add_expr *right;
  struct shift_expr *left;
  int op;
  ast_node_t *node;
} shift_expr_t;

#endif
