#ifndef ALIGNMENT_SPECIFIER_H
#define ALIGNMENT_SPECIFIER_H

/**
 * alignment-specifier:
 *      ALIGNAS '(' type-name ')'       (1)
 *      ALIGNAS '(' constant-expression ')'     (2)
 * 
 * parents:
 *      declaration-specifiers (9)(10)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

typedef enum
{
  ALIGN_TYPE_NAME,
  ALIGN_CONST_EXPR
} align_kind_t;

struct alignment_specifier
{
  node_kind_t kind;
  align_kind_t a_kind;
  union
  {
    struct type_name *tn;
    struct constant_expression *expr;
  };
  struct symtable *sym_table;
  void (*create_symtable) (struct alignment_specifier * buff);
  void (*create_symbol) (struct alignment_specifier * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
