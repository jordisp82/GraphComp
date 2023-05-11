#ifndef ASS_EXPR_T_H
#define ASS_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct ass_expr
{
  union
  {
    struct cond_expr *cond_expr;
    struct
    {
      struct unary_expr *unary_expr;
      int ass_op;
      struct ass_expr *ass_expr;
    };
  };
  ast_node_t *node;
} ass_expr_t;

#endif
