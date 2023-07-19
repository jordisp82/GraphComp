#ifndef ATOMIC_TYPE_SPECIFIER_H
#define ATOMIC_TYPE_SPECIFIER_H

/**
 * atomic-type-specifier:
 *      ATOMIC '(' type-name ')'
 * 
 * parents:
 *      type-specifier (13)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct atomic_type_specifier
{
  node_kind_t kind;
  struct type_name *tn;
  struct symtable *sym_table;
  void (*create_symtable) (struct atomic_type_specifier * buff);
  void (*create_symbol) (struct atomic_type_specifier * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
