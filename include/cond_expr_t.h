#ifndef COND_EXPR_T_H
#define COND_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct cond_expr
{
  struct log_or_expr *first;
  struct expression *second;
  struct cond_expr *third;
  ast_node_t *node;
} cond_expr_t;

#endif
