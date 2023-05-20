#ifndef PARAMETER_TYPE_LIST_H
#define PARAMETER_TYPE_LIST_H

/**
 * parameter-type-list:
 *      parameter-list ',' ELLIPSIS     (1)
 *      parameter-list                  (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct parameter_type_list
{
  node_kind_t kind;
  struct parameter_list *pl;
  int ellipsis;
  node_kind_t parent_kind;
  void *parent;
};

#endif
