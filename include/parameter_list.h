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
#include "symtable.h"

struct parameter_list
{
  node_kind_t kind;
  struct pl_node
  {
    struct parameter_declaration *pd;
    struct pl_node *next;
  } *first, *last;
  struct symtable *sym_table;
  void (*create_symtable) (struct parameter_list * buff);
  void (*create_symbol) (struct parameter_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
