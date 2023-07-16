#ifndef STRUCT_DECLARATION_LIST_H
#define STRUCT_DECLARATION_LIST_H

/**
 * struct-declaration-list:
 *      struct-declaration              (1)
 *      struct-declaration-list struct-declaration      (2)
 * 
 * parents:
 *      struct-or-union-specifier (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct struct_declaration_list
{
  node_kind_t kind;
  struct sdln_node
  {
    struct struct_declaration *sd;
    struct sdln_node *next;
  } *first, *last;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct struct_declaration_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_struct_declaration_list_scope (struct struct_declaration_list *buff);
#endif

#endif
