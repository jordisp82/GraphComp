#ifndef BLOCK_ITEM_LIST_H
#define BLOCK_ITEM_LIST_H

/**
 * block-item-list:
 *      block-item      (1)
 *      block-item-list block-item      (2)
 * 
 * We're going to apply the same technique
 * as in the case of the translation-unit
 */

typedef enum
{
  NODE_BLOCK_ITEM_LIST
} node_kind_t;

struct block_item;

struct block_item_list
{
  node_kind_t kind;             // NODE_BLOCK_ITEM_LIST
  struct bil_node
  {
    struct block_item *block_item;
    struct bil_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif
