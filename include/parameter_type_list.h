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
#include "symbol.h"

struct parameter_type_list
{
  node_kind_t kind;
  struct parameter_list *pl;
  int ellipsis;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

int create_symbols_for_param_tlist (struct parameter_type_list *buff,
                                    symbol_t *** sym_pars);
void set_parameter_type_list_scope (struct parameter_type_list *buff);

#endif
