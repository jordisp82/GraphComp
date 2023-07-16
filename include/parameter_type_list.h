#ifndef PARAMETER_TYPE_LIST_H
#define PARAMETER_TYPE_LIST_H

/**
 * parameter-type-list:
 *      parameter-list ',' ELLIPSIS     (1)
 *      parameter-list                  (2)
 * 
 * parents:
 *      direct-declarator (12)
 *      direct-abstract-declarator (19)(21)
 */

#include "node_kind_t.h"
#include "structs.h"
//#include "symbol.h"
#include "symtable.h"

struct parameter_type_list
{
  node_kind_t kind;
  struct parameter_list *pl;
  int ellipsis;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct parameter_type_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
int create_symbols_for_param_tlist (struct parameter_type_list *buff,
                                    symbol_t *** sym_pars);
void set_parameter_type_list_scope (struct parameter_type_list *buff);
#endif

#endif
