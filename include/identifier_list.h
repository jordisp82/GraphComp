#ifndef IDENTIFIER_LIST_H
#define IDENTIFIER_LIST_H

/**
 * identifier-list:
 *      IDENTIFIER          (1)
 *      identifier-list ',' IDENTIFIER      (2)
 * 
 * parents:
 *      direct-declarator (14)
 *      identifier-list (2)
 */

#include "node_kind_t.h"

struct identifier_list
{
  node_kind_t kind;
  struct il_node
  {
    const char *str;
    struct il_node *next;
  } *first, *last;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
