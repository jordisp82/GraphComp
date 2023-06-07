#ifndef INCLUSIVE_OR_EXPRESSION_H
#define INCLUSIVE_OR_EXPRESSION_H

/**
 * inclusive-or-expression:
 *      exclusive-or-expression           (1)
 *      inclusive-or-expression '|' exclusive-or-expression (2)
 * 
 * parents:
 *      logical-and-expression (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct inclusive_or_expression
{
  node_kind_t kind;
  struct exclusive_or_expression *xor_e;
  struct inclusive_or_expression *or_e;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_or_expression_scope (struct inclusive_or_expression *buff);

#endif
