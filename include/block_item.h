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
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_block_item_scope (struct block_item *buff);
void fill_in_symtable_block_item (struct block_item *buff);

#endif
