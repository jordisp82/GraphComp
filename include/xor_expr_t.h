#ifndef XOR_EXPR_T_H
#define XOR_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct xor_expr
{
  struct bin_and_expr *right;
  struct xor_expr *left;
  int op;
  ast_node_t *node;
} xor_expr_t;

#endif
