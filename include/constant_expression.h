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
#include "symtable.h"

struct constant_expression
{
  node_kind_t kind;
  struct conditional_expression *expr;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct constant_expression * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_const_expression_scope (struct constant_expression *buff);
void set_symbol_for_constant_expression (struct constant_expression *buff);
#endif

#endif
