#ifndef EXPRESSION_T_H
#define EXPRESSION_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct expression
{
  struct ass_expr *right;
  struct expression *left;
  ast_node_t *node;
} expression_t;

#endif
