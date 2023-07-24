#ifndef SHIFT_EXPRESSION
#define SHIFT_EXPRESSION

/**
 * shift-expression:
 *      additive-expression         (1)
 *      shift-expression LEFT_OP additive-expression        (2)
 *      shift-expression RIGHT_OP additive-expression       (3)
 * 
 * parents:
 *      relational-expression (1)(2)(3)(4)(5)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

typedef enum
{
  SHIFT_NONE,
  SHIFT_LEFT,
  SHIFT_RIGHT
} sh_kind_t;

struct shift_expression
{
  node_kind_t kind;
  sh_kind_t sh_kind;
  struct additive_expression *add_ex;
  struct shift_expression *sh_ex;
  struct symtable *sym_table;
  void (*create_symtable) (struct shift_expression * buff);
  void (*create_symbol) (struct shift_expression * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
