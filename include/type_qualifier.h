#ifndef TYPE_QUALIFIER_H
#define TYPE_QUALIFIER_H

/**
 * type-qualifier:
 *      CONST       (1)
 *      RESTRICT    (2)
 *      VOLATILE    (3)
 *      ATOMIC      (4)
 * 
 * parents:
 *      declaration-specifiers (5)(6)
 *      specifier-qualifier-list (3)(4)
 *      type-qualifier-list (1)(2)
 */

#include "node_kind_t.h"
#include "symtable.h"

typedef enum
{
  TQ_CONST,
  TQ_RESTRICT,
  TQ_VOLATILE,
  TQ_ATOMIC
} tq_kind_t;

struct type_qualifier
{
  node_kind_t kind;
  tq_kind_t tq_kind;
  struct symtable *sym_table;
  void (*create_symtable) (struct type_qualifier * buff);
  void (*create_symbol) (struct type_qualifier * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
