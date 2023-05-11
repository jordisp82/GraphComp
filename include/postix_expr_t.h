#ifndef POSTFIX_EXPR_T_H
#define POSTFIX_EXPR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  POSTFIX_PRI,                  /* postfix_expression_1 */
  POSTFIX_ARRAY,                /* postfix_expression_2 */
  POSTFIX_FUNC,                 /* postfix_expression_3, postfix_expression_4 */
  POSTFIX_MEMB1,                /* postfix_expression_5 */
  POSTFIX_MEMB2,                /* postfix_expression_6 */
  POSTFIX_INCR,                 /* postfix_expression_7 */
  POSTFIX_DECR,                 /* postfix_expression_8 */
  POSTFIX_CLIT,                 /* postfix_expression_9, postfix_expression_10 */
} postfix_expr_kind_t;

typedef struct postfix_expr
{
  postfix_expr_kind_t kind;
  struct postfix_expr *left;
  union
  {
    struct prim_expr *prim;     /* POSTFIX_PRI */
    struct expression *array;   /* POSTFIX_ARRAY */
    /* TODO POSTFIX_FUNC */
    const char *str;            /* POSTFIX_MEMB1, POSTFIX_MEMB2 */
    /* NOTE none needed for POSTFIX_INCR, POSTFIX_DECR */
    /* TODO POSTFIX_CLIT */
  };
  ast_node_t *node;
} postfix_expr_t;

#endif
