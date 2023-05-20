#ifndef BLOCK_ITEM_LIST_H
#define BLOCK_ITEM_LIST_H

/**
 * block-item-list:
 *      block-item      (1)
 *      block-item-list block-item      (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct block_item_list
{
  node_kind_t kind;
  struct bil_node
  {
    struct block_item *block_item;
    struct bil_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif
