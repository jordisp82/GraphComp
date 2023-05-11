#ifndef CAST_EXPR_T_H
#define CAST_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  CSEXPR_UNARY,                 /* cast_expression_1 */
  CSEXPR_CAST                   /* cast_expression_2 */
} cast_expr_kind_t;

typedef struct cast_expr
{
  cast_expr_kind_t kind;
  union
  {
    struct unary_expr *unary_expr;      /* CSEXPR_UNARY */
    struct
    {
      /* TODO type_name */
      struct cast_expr *cast_expr;
    };                          /* CSEXPR_CAST */
  };
  ast_node_t *node;
} cast_expr_t;

#endif
