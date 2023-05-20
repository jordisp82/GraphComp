#ifndef IDENTIFIER_LIST_H
#define IDENTIFIER_LIST_H

/**
 * identifier-list:
 *      IDENTIFIER          (1)
 *      identifier-list ',' IDENTIFIER      (2)
 * 
 * As the other lists.
 */

#include "node_kind_t.h"

struct identifier_list
{
  node_kind_t kind;
  struct idl_node
  {
    const char *str;
    struct idl_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif
