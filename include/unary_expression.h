#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

/**
 * unary-expression:
 *      postfix-expression                  (1)
 *      INC_OP unary-expression             (2)
 *      DEC_OP unary-expression             (3)
 *      unary-operator cast-expression      (4)
 *      SIZEOF unary-expression             (5)
 *      SIZEOF '(' type-name ')'            (6)
 *      ALIGNOF '(' type-name ')'           (7)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  UNARY_POSTFIX,
  UNARY_INC,
  UNARY_DEC,
  UNARY_OP,
  UNARY_SIZEOF1,
  UNARY_SIZEOF2,
  UNARY_ALIGNOF
} unary_kind_t;

struct unary_expression
{
  node_kind_t kind;
  unary_kind_t unary_kind;
  struct postfix_expression *pex;
  struct unary_expression *unex;
  struct unary_operator *unop;
  struct cast_expression *cex;
  struct type_name *tn;
  node_kind_t parent_kind;
  void *parent;
};

#endif
