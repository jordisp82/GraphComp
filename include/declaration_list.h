#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

/**
 * declaration-list:
 *      declaration         (1)
 *      declaration-list declaration        (2)
 * 
 * parents:
 *      function-definition (1)
 */

#include "node_kind_t.h"
#include "structs.h"

struct declaration_list
{
  node_kind_t kind;
  struct dl_node
  {
    struct declaration *dl;
    struct dl_node *next;
  } *first, *last;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
