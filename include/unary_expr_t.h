#ifndef UNARY_EXPR_T_H
#define UNARY_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  UNEXPR_POSTFIX,               /* unary_expression_1 */
  UNEXPR_INCR,                  /* unary_expression_2 */
  UNEXPR_DECR,                  /* unary_expression_3 */
  UNEXPR_UNOP,                  /* unary_expression_4 */
  UNEXPR_SIZEOF1,               /* unary_expression_5 */
  UNEXPR_SIZEOF2,               /* unary_expression_6 */
  UNEXPR_ALIGNOF,               /* unary_expression_7 */
} unary_expr_kind_t;

typedef struct unary_expr
{
  unary_expr_kind_t kind;
  struct unary_expr *right;
  union
  {
    struct postfix_expr *postfix;       /* UNEXPR_POSTFIX */
    /* NOTE none needed for UNEXPR_INCR, UNEXPR_DECR */
    struct
    {
      int un_op;
      struct cast_expr *cast_expr;
    };                          /* UNEXPR_UNOP */
    struct unary_expr *unary_expr;      /* UNEXPR_SIZEOF1 */
    struct type_name *type_name;        /* UNEXPR_SIZEOF2, UNEXPR_ALIGNOF */
  };
  ast_node_t *node;
} unary_expr_t;

#endif
