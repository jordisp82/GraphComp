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

struct parameter_list
{
  node_kind_t kind;
  struct pl_node
  {
    struct parameter_declaration *pd;
    struct pl_node *next;
  } *first, *last;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
