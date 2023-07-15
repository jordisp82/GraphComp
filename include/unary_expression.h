#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

/**
 * unary-expression:
 *      postfix-expression                  (1)
 *      INC_OP unary-expression             (2)
 *      DEC_OP unary-expression             (3)
 *      unary-operator cast-expression      (4)
 *      SIZEOF unary-expression             (5)
 *      SIZEOF '(' type-name ')'            (6)
 *      ALIGNOF '(' type-name ')'           (7)
 * 
 * parents:
 *      cast-expression (1)
 *      assignment-expression (2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

typedef enum
{
  UNARY_POSTFIX,
  UNARY_INC,
  UNARY_DEC,
  UNARY_OP,
  UNARY_SIZEOF1,
  UNARY_SIZEOF2,
  UNARY_ALIGNOF
} unary_kind_t;

struct unary_expression
{
  node_kind_t kind;
  unary_kind_t unary_kind;
  struct postfix_expression *pex;
  struct unary_expression *unex;
  struct unary_operator *unop;
  struct cast_expression *cex;
  struct type_name *tn;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct unary_expression * buff);
  node_kind_t parent_kind;
  void *parent;
};

void set_unary_expression_scope (struct unary_expression *buff);
void set_symbol_for_unary_expression (struct unary_expression *buff);

#endif
