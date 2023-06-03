#ifndef ASSIGNMENT_EXPRESSION_H
#define ASSIGNMENT_EXPRESSION_H

/**
 * assignment-expression:
 *      conditional-expression           (1)
 *      unary-expression assignment-operator assignment-expression    (2)
 * 
 * parents:
 *      ignoring generic-selection and generic-association
 *      argument-expression-list (1)(2)
 *      expression (1)(2)
 *      direct-declarator (5)(6)(8)(9)(11)
 *      direct-abstract-declarator (4)(5)(6)(7)(9)(12)(13)(14)(15)(17)
 *      initializer (3)
 */

#include "node_kind_t.h"
#include "structs.h"

struct assignment_expression
{
  node_kind_t kind;
  struct conditional_expression *cond_e;
  struct unary_expression *un_expr;
  struct assignment_operator *ass_op;
  struct assignment_expression *ass_e;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_assignment_expression_scope (struct assignment_expression *buff);
void fill_in_symtable_ass_expr (struct assignment_expression *buff);

#endif
