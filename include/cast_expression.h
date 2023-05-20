#ifndef CAST_EXPRESSION_H
#define CAST_EXPRESSION_H

/**
 * cast-expression:
 *      unary-expression            (1)
 *      '(' type-name ')' cast-expression   (2)
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
  struct unary_expression *unary_ex;
  struct type_name *tn;
  node_kind_t parent_kind;
  void *parent;
};

#endif