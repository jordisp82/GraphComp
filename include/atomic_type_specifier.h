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
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct atomic_type_specifier * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_atomic_specifier_scope (struct atomic_type_specifier *buff);
#endif

#endif
