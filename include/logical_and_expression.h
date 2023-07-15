#ifndef LOGICAL_AND_EXPRESSION_H
#define LOGICAL_AND_EXPRESSION_H

/**
 * logical-and-expression:
 *      inclusive-or-expression           (1)
 *      logical-and-expression AND_OP inclusive-or-expression (2)
 * 
 * parents:
 *      logical-or-expression (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct logical_and_expression
{
  node_kind_t kind;
  struct inclusive_or_expression *inc_or;
  struct logical_and_expression *log_and;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct logical_and_expression * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_logic_and_expression_scope (struct logical_and_expression *buff);
void set_symbol_for_logic_and_expression (struct logical_and_expression
                                          *buff);
#endif

#endif
