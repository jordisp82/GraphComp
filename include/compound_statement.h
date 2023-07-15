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
 * 
 * parents:
 *      statement (2)
 *      function-definition (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
//#include "avl_tree.h"
#include "symtable.h"

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
#if 0
  avl_node_t *ordinary;
  avl_node_t *tags;
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct compound_statement * buff);
  node_kind_t parent_kind;
  void *parent;                 /* void * for now */
};

#if 0
void create_symbol_table_cs (struct compound_statement *buff);
void set_compound_stmt_scope (struct compound_statement *buff);
symbol_t *look_for_id_in_cs (struct compound_statement *buff,
                             const char *name);
void set_symbol_for_compound_stmt (struct compound_statement *buff);
#endif

#endif
