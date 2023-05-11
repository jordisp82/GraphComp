#ifndef PRIM_EXPR_T_H
#define PRIM_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  PREXPR_ID,                    /* primary_expression_1 */
  PREXPR_CONST_I,               /* primary_expression_2, constant_1 */
  PREXPR_CONST_F,               /* primary_expression_2, constant_2 */
  PREXPR_CONST_E,               /* primary_expression_2, constant_3 */
  PREXPR_STRING,                /* primary_expression_3, string_1 */
  PREXPR_FUNCNAM,               /* primary_expression_3, string_2 */
  PREXPR_EXPR,                  /* primary_expression_4 */
  PREXPR_GENERIC                /* primary_expression_5 */
} prim_expr_kind_t;

typedef struct prim_expr
{
  prim_expr_kind_t kind;
  ast_node_t *node;
  union
  {
    const char *str;            /* PREXPR_ID, PREXPR_CONST_E PREXPR_STRING, PREXPR_EXPR */
    long long int iv;           /* PREXPR_CONST_I */
    double dv;                  /* PREXPR_CONST_F */
    struct expression *expr;    /* PREXPR_EXPR */
    /* TODO generic selection */
  };
} prim_expr_t;

#endif
