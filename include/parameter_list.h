#ifndef PARAMETER_LIST_H
#define PARAMETER_LIST_H

/**
 * parameter-list:
 *      parameter-declaration       (1)
 *      parameter-list ',' parameter-declaration        (2)
 * 
 * parents:
 *      parameter-type-list (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
//#include "symbol.h"
#include "symtable.h"

struct parameter_list
{
  node_kind_t kind;
  struct pl_node
  {
    struct parameter_declaration *pd;
    struct pl_node *next;
  } *first, *last;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct parameter_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
int create_symbols_for_param_list (struct parameter_list *buff,
                                   symbol_t *** sym_pars);
void set_parameter_list_scope (struct parameter_list *buff);
#endif

#endif
