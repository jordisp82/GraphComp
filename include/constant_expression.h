#ifndef CONSTANT_EXPRESSION_H
#define CONSTANT_EXPRESSION_H

/**
 * constant-expression:
 *      conditional-expression
 */

#include "node_kind_t.h"
#include "structs.h"

struct constant_expression
{
  node_kind_t kind;
  struct conditional_expression *expr;
  node_kind_t parent_kind;
  void *parent;
};

#endif
