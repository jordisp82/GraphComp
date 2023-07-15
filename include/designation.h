#ifndef DESIGNATION_H
#define DESIGNATION_H

/**
 * designation:
 *      designator-list '='
 * 
 * parents:
 *      initializer-list (1)(3)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct designation
{
  node_kind_t kind;
  struct designator_list *dl;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct designation * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_designation_scope (struct designation *buff);
void set_symbol_for_designation (struct designation *buff);
#endif

#endif
