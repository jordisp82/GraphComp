#ifndef EXPRESSION_H
#define EXPRESSION_H

/**
 * expression:
 *      assignment-expression           (1)
 *      expression ',' assignment-expression    (2)
 * 
 * parents:
 *      primary-expression (4)
 *      postfix-expression (2)
 *      conditional-expression (2)
 *      expression-statement (2)
 *      selection-statement (1)(2)(3)
 *      iteration-statement (1)(2)(4)(6)
 *      jump-statement (5)
 */

#include "node_kind_t.h"
#include "structs.h"

struct expression
{
  node_kind_t kind;
  struct expression *expr;
  struct assignment_expression *ass;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_expression_scope (struct expression *buff);
void set_symbol_for_expression (struct expression *buff);

#endif
