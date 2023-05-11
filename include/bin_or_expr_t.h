#ifndef BIN_OR_EXPR_T_H
#define BIN_OR_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct bin_or_expr
{
  struct xor_expr *right;
  struct bin_or_expr *left;
  int op;
  ast_node_t *node;
} bin_or_expr_t;

#endif
