#ifndef ARGUMENT_EXPRESSION_LIST_H
#define ARGUMENT_EXPRESSION_LIST_H

/**
 * argument-expression-list:
 *      assignment-expression           (1)
 *      argument-expression-list ',' assignment-expression      (2)
 * 
 * parents:
 *      postfix_expression (4)
 */

#include "node_kind_t.h"
#include "structs.h"

struct argument_expression_list
{
  node_kind_t kind;
  struct ael_node
  {
    struct assignment_expression *ass;
    struct ael_node *next;
  } *first, *last;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_argument_expression_list_scope (struct argument_expression_list
                                         *buff);
void set_symbol_for_argument_expression_list (struct argument_expression_list
                                              *buff);

#endif
