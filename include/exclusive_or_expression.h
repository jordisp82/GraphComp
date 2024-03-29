#ifndef EXCLUSIVE_OR_EXPRESSION_H
#define EXCLUSIVE_OR_EXPRESSION_H

/**
 * exclusive-or-expression:
 *      and-expression           (1)
 *      exclusive-or-expression '^' and-expression (2)
 * 
 * parents:
 *      inclusive-or-expression (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct exclusive_or_expression
{
  node_kind_t kind;
  struct and_expression *and_e;
  struct exclusive_or_expression *xor_e;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
