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
//#include "symbol.h"
#include "symtable.h"

struct init_declarator
{
  node_kind_t kind;
  struct declarator *dclr;
  struct initializer *itz;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct init_declarator * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
symbol_t *create_symbol_from_init_declarator (struct init_declarator *buff);
void set_init_declarator_scope (struct init_declarator *buff);
void set_symbol_for_init_declarator (struct init_declarator *buff);
#endif

#endif
