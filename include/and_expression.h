#ifndef AND_EXPRESSION_H
#define AND_EXPRESSION_H

/**
 * and-expression:
 *      equality-expression           (1)
 *      and-expression '&' equality-expression (2)
 * 
 * parents:
 *      exclusive-or-expression (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct and_expression
{
  node_kind_t kind;
  struct equality_expression *eq;
  struct and_expression *and_e;
  struct symtable *sym_table;
  void (*create_symtable) (struct and_expression * buff);
  void (*create_symbol) (struct and_expression * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
