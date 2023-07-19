#ifndef INIT_DECLARATOR_H
#define INIT_DECLARATOR_H

/**
 * init-declarator:
 *      declarator '=' initializer          (1)
 *      declarator          (2)
 * 
 * parents:
 *      init-declarator-list (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct init_declarator
{
  node_kind_t kind;
  struct declarator *dclr;
  struct initializer *itz;
  struct symtable *sym_table;
  void (*create_symtable) (struct init_declarator * buff);
  void (*create_symbol) (struct init_declarator * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
