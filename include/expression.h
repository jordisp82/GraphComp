#ifndef EXPRESSION_H
#define EXPRESSION_H

/**
 * expression:
 *      assignment-expression           (1)
 *      expression ',' assignment-expression    (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct expression
{
  node_kind_t kind;
  struct expression *expr;
  struct assignment_expression *ass;
  node_kind_t parent_kind;
  void *parent;
};

#endif
