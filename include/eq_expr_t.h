#ifndef EQ_EXPR_T_H
#define EQ_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct equal_expr
{
  struct rel_expr *right;
  struct equal_expr *left;
  int op;
  ast_node_t *node;
} equal_expr_t;

#endif
