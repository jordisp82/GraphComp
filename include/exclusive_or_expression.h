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
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_xor_expression_scope (struct exclusive_or_expression *buff);

#endif
