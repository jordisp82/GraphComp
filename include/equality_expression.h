#ifndef EQUALITY_EXPRESSION_H
#define EQUALITY_EXPRESSION_H

/**
 * equality-expression:
 *      relational-expression           (1)
 *      equality-expression EQ_OP relational-expression     (2)
 *      equality-expression NE_OP relational-expression     (3)
 * 
 * parents:
 *      and-expression (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

typedef enum
{
  EQ_NO_OP,
  EQ_EQUAL,
  EQ_NOT_EQUAL
} eq_kind_t;

struct equality_expression
{
  node_kind_t kind;
  eq_kind_t eq_kind;
  struct relational_expression *rexp;
  struct equality_expression *eqex;
  struct symtable *sym_table;
  void (*create_symtable) (struct equality_expression * buff);
  void (*create_symbol) (struct equality_expression * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
