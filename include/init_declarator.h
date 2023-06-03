#ifndef INIT_DECLARATOR_H
#define INIT_DECLARATOR_H

/**
 * init-declarator:
 *      declarator '=' initializer          (1)
 *      declarator          (2)
 * 
 * parents:
 *      declaration (2)
 *      init-declarator-list (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symbol.h"

struct init_declarator
{
  node_kind_t kind;
  struct declarator *dclr;
  struct initializer *itz;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

symbol_t *create_symbol_from_init_declarator (struct init_declarator *buff);
void set_init_declarator_scope (struct init_declarator *buff);
void fill_in_symtable_init_declarator (struct init_declarator *buff);

#endif
