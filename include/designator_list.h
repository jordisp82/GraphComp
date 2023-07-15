#ifndef DESIGNATOR_LIST_H
#define DESIGNATOR_LIST_H

/**
 * designator-list:
 *      designator          (1)
 *      designator-list designator      (2)
 * 
 * parents:
 *      designation (1)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct designator_list
{
  node_kind_t kind;
  struct ds_node
  {
    struct designator *ds;
    struct ds_node *next;
  } *first, *last;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct designator_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_designator_list_scope (struct designator_list *buff);
void set_symbol_for_designator_list (struct designator_list *buff);
#endif

#endif
