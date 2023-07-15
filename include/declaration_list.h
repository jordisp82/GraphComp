#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

/**
 * declaration-list:
 *      declaration         (1)
 *      declaration-list declaration        (2)
 * 
 * parents:
 *      function-definition (1)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct declaration_list
{
  node_kind_t kind;
  struct dl_node
  {
    struct declaration *dl;
    struct dl_node *next;
  } *first, *last;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct declaration_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_declaration_list_scope (struct declaration_list *buff);
void set_symbol_for_declaration_list (struct declaration_list *buff);
#endif

#endif
