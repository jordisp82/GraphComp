#ifndef ENUMERATOR_LIST_H
#define ENUMERATOR_LIST_H

/**
 * enumerator-list:
 *      enumerator      (1)
 *      enumerator-list ',' enumerator      (2)
 * 
 * parents:
 *      enum-specifier (1)(2)(3)(4)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct enumerator_list
{
  node_kind_t kind;
  struct enl_node
  {
    struct enumerator *en;
    struct enl_node *next;
  } *first, *last;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct enumerator_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_enumerator_list_scope (struct enumerator_list *buff);
#endif

#endif
