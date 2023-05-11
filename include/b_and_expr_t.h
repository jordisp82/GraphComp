#ifndef B_AND_EXPR_T_H
#define B_AND_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct bin_and_expr
{
  struct equal_expr *right;
  struct bin_and_expr *left;
  int op;
  ast_node_t *node;
} bin_and_expr_t;

#endif
