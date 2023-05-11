#ifndef LOG_OR_EXPR_T_H
#define LOG_OR_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct log_or_expr
{
  struct log_and_expr *right;
  struct log_or_expr *left;
  int op;
  ast_node_t *node;
} log_or_expr_t;

#endif
