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
#include "symbol.h"

struct init_declarator_list
{
  node_kind_t kind;
  struct idl_node
  {
    struct init_declarator *id;
    struct idl_node *next;
  } *first, *last;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

int create_symbols_for_init_declarator_list (struct init_declarator_list
                                             *buff, symbol_t *** syms);
void set_init_declarator_list_scope (struct init_declarator_list *buff);
void set_symbol_for_init_declarator_list (struct init_declarator_list *buff);

#endif
