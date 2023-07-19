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
#include "symtable.h"

struct block_item
{
  node_kind_t kind;
  node_kind_t child_kind;
  union
  {
    struct declaration *d;
    struct statement *s;
  };
  struct symtable *sym_table;
  void (*create_symtable) (struct block_item * buff);
  void (*create_symbol) (struct block_item * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
