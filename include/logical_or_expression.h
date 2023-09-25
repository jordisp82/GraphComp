#ifndef LOGICAL_OR_EXPRESSION_H
#define LOGICAL_OR_EXPRESSION_H

/**
 * logical-or-expression:
 *      logical-and-expression           (1)
 *      logical-or-expression OR_OP logical-and-expression (2)
 * 
 * parents:
 *      conditional-expression (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct logical_or_expression
{
  node_kind_t kind;
  struct logical_and_expression *and_e;
  struct logical_or_expression *or_e;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
