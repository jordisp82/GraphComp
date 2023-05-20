#ifndef ENUMERATOR_LIST_H
#define ENUMERATOR_LIST_H

/**
 * enumerator-list:
 *      enumerator      (1)
 *      enumerator-list ',' enumerator      (2)
 * 
 * Another list.
 */

#include "node_kind_t.h"
#include "structs.h"

struct enumerator_list
{
  node_kind_t kind;
  struct enl_node
  {
    struct enumerator *en;
    struct enl_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif
