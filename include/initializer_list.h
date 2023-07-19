#ifndef INITIALIZER_LIST_H
#define INITIALIZER_LIST_H

/**
 * initializer-list:
 *      designation initializer         (1)
 *      initializer             (2)
 *      initializer-list ',' designation initializer        (3)
 *      initializer-list ',' initializer        (4)
 * 
 * parents:
 *      postfix-expression (9)(10)
 *      initializer (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

typedef enum
{
  IL_D_I,
  IL_I
} il_node_kind_t;

struct initializer_list
{
  node_kind_t kind;
  struct il_node
  {
    il_node_kind_t il_kind;
    struct designation *d;
    struct initializer *i;
    struct il_node *next;
  } *first, *last;
  struct symtable *sym_table;
  void (*create_symtable) (struct initializer_list * buff);
  void (*create_symbol) (struct initializer_list * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
