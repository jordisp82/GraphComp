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
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
