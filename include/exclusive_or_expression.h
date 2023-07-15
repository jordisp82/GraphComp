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
#include "symtable.h"

struct exclusive_or_expression
{
  node_kind_t kind;
  struct and_expression *and_e;
  struct exclusive_or_expression *xor_e;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct exclusive_or_expression * buff);
  node_kind_t parent_kind;
  void *parent;
};

void set_xor_expression_scope (struct exclusive_or_expression *buff);
void set_symbol_for_xor_expression (struct exclusive_or_expression *buff);

#endif
