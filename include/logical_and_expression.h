#ifndef LOGICAL_AND_EXPRESSION_H
#define LOGICAL_AND_EXPRESSION_H

/**
 * logical-and-expression:
 *      inclusive-or-expression           (1)
 *      logical-and-expression AND_OP inclusive-or-expression (2)
 * 
 * parents:
 *      logical-or-expression (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct logical_and_expression
{
  node_kind_t kind;
  struct inclusive_or_expression *inc_or;
  struct logical_and_expression *log_and;
  node_kind_t parent_kind;
  void *parent;
};

#endif
