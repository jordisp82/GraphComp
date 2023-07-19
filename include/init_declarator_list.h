#ifndef INIT_DECLARATOR_LIST_H
#define INIT_DECLARATOR_LIST_H

/**
 * init-declarator-list:
 *      init-declarator         (1)
 *      init-declarator-list ',' init-declarator    (2)
 * 
 * parents:
 *      declaration (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct init_declarator_list
{
  node_kind_t kind;
  struct idl_node
  {
    struct init_declarator *id;
    struct idl_node *next;
  } *first, *last;
  struct symtable *sym_table;
  void (*create_symtable) (struct init_declarator_list * buff);
  void (*create_symbol) (struct init_declarator_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
