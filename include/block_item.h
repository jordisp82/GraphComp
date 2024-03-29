#ifndef BLOCK_ITEM_H
#define BLOCK_ITEM_H

/**
 * block-item:
 *      declaration     (1)
 *      statement       (2)
 * 
 * parents:
 *      block-item-list (1), (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct block_item
{
  node_kind_t kind;
  node_kind_t child_kind;
  union
  {
    struct declaration *d;
    struct statement *s;
  };
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
