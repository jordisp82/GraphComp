#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

/**
 * unary-operator:
 *      '&'
 *      '*'
 *      '+'
 *      '-'
 *      '~'
 *      '!'
 * 
 * parents:
 *      unary-expression (4)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

typedef enum
{
  UNOP_AMPERSAND,
  UNOP_STAR,
  UNOP_PLUS,
  UNOP_DASH,
  UNOP_TILDE,
  UNOP_EXCLAMATION
} unop_kind_t;

struct unary_operator
{
  node_kind_t kind;
  unop_kind_t un_op;
  struct symtable *sym_table;
  void (*create_symtable) (struct unary_operator * buff);
  void (*create_symbol) (struct unary_operator * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
