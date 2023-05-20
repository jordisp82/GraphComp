#ifndef MULTIPLICATIVE_EXPRESSION
#define MULTIPLICATIVE_EXPRESSION

/**
 * multiplicative-expression:
 *      cast-expression             (1)
 *      multiplicative-expression '*' cast-expression       (2)
 *      multiplicative-expression '/' cast-expression       (3)
 *      multiplicative-expression '%' cast-expression       (4)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  MULT_NONE,
  MULT_STAR,
  MULT_SLASH,
  MULT_MODULO
} mult_kind_t;

struct multiplicative_expression
{
  node_kind_t kind;
  mult_kind_t mult_kind;
  struct cast_expression *cast_ex;
  struct multiplicative_expression *mult_ex;
  node_kind_t parent_kind;
  void *parent;
};

#endif