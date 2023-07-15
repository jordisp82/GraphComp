#ifndef BLOCK_ITEM_LIST_H
#define BLOCK_ITEM_LIST_H

/**
 * block-item-list:
 *      block-item      (1)
 *      block-item-list block-item      (2)
 * 
 * parents:
 *      compount-statement (2)
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
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct block_item_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_block_item_list_scope (struct block_item_list *buff);
void set_symbol_for_block_item_list (struct block_item_list *buff);
#endif

#endif
