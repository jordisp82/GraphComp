#ifndef CONDITIONAL_EXPRESSION_H
#define CONDITIONAL_EXPRESSION_H

/**
 * conditional-expression:
 *      logical-or-expression           (1)
 *      logical-or-expression '?' expression ':' conditional-expression (2)
 * 
 * parents:
 *      assignment-expression (1)
 *      constant-expression (1)
 */

#include "node_kind_t.h"
#include "structs.h"

struct conditional_expression
{
  node_kind_t kind;
  struct logical_or_expression *l_expr;
  struct expression *expr;
  struct conditional_expression *cond_e;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_cond_expression_scope (struct conditional_expression *buff);
void set_symbol_for_cond_expression (struct conditional_expression *buff);

#endif
