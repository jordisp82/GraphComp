#ifndef CONSTANT_EXPRESSION_H
#define CONSTANT_EXPRESSION_H

/**
 * constant-expression:
 *      conditional-expression
 * 
 * parents:
 *      struct-declarator (1)(2)
 *      enumerator (1)
 *      alignment-specifier (2)
 *      designator (1)
 *      static-assert-declaration (1)
 *      labeled-statement (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct constant_expression
{
  node_kind_t kind;
  struct conditional_expression *expr;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
