#ifndef LOG_AND_EXPR_T_H
#define LOG_AND_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct log_and_expr
{
  struct bin_or_expr *right;
  struct log_and_expr *left;
  int op;
  ast_node_t *node;
} log_and_expr_t;

#endif
