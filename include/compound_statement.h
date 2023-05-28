#ifndef COMPOUND_STATEMENT_H
#define COMPOUND_STATEMENT_H

/**
 * compound-statement:
 *      '{' '}'         (1)
 *      '{' block-item-list '}'     (2)
 * 
 * Rule (1) only poses a question: whether to return NULL,
 * or not. Rule (2) has something with "list" in its name, but
 * is it really a list? Oh yes it is. No problem, we'll treat it
 * in the same way as a translation unit.
 */

#include "node_kind_t.h"
#include "structs.h"
#include "avl_tree.h"

typedef enum
{
  CS_EMPTY,
  CS_BLOCK_ITEM_LIST
} cs_kind_t;

struct compound_statement
{
  node_kind_t kind;
  cs_kind_t cs_kind;
  struct block_item_list *bil;  /* only for CS_BLOCK_ITEM_LIST */
  avl_node_t *ordinary;
  avl_node_t *tags;
  node_kind_t parent_kind;
  void *parent;                 /* void * for now */
};

void create_symbol_table_cs (struct compound_statement *buff);

#endif
