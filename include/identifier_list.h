#ifndef IDENTIFIER_LIST_H
#define IDENTIFIER_LIST_H

/**
 * identifier-list:
 *      IDENTIFIER          (1)
 *      identifier-list ',' IDENTIFIER      (2)
 * 
 * parents:
 *      direct-declarator (14)
 *      identifier-list (2)
 */

#include "node_kind_t.h"
#include "symtable.h"
#include "symbol.h"

struct identifier_list
{
  node_kind_t kind;
  struct il_node
  {
    const char *str;
    struct symbol *sym;
    struct il_node *next;
  } *first, *last;
  struct symtable *sym_table;
  void (*create_symtable) (struct identifier_list * buff);
  void (*create_symbol) (struct identifier_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
