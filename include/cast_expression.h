#ifndef CAST_EXPRESSION_H
#define CAST_EXPRESSION_H

/**
 * cast-expression:
 *      unary-expression            (1)
 *      '(' type-name ')' cast-expression   (2)
 * 
 * parents:
 *      unary-expression (4)
 *      multiplicative-expression (1)(2)(3)(4)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  CAST_NO,
  CAST_YES
} cast_kind_t;

struct cast_expression
{
  node_kind_t kind;
  cast_kind_t cast_kind;
  union
  {
    struct unary_expression *unary_ex;
    struct cast_expression *cast_ex;
  };
  void (*dot_create) (void *node, void *f);
  struct type_name *tn;
  node_kind_t parent_kind;
  void *parent;
};

#endif
