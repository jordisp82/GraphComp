#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

/**
 * declaration-list:
 *      declaration         (1)
 *      declaration-list declaration        (2)
 * 
 * As in the case of the translation-unit and
 * block-item-list.
 */

#include "node_kind_t.h"
#include "structs.h"

struct declaration_list
{
  node_kind_t kind;             // NODE_DECLARATION_LIST
  struct dl_node
  {
    struct declaration *dl;
    struct dl_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif
