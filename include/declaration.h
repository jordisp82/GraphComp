#ifndef DECLARATION_H
#define DECLARATION_H

/**
 * declaration:
 *      declaration-specifiers ';'              (1)
 *      declaration-specifiers init-declarator-list ';'        (2)
 *      static_assert-declaration               (3)
 * 
 * Possible parents:
 *      block-item (1)
 *      iteration-statement (5)(6)
 *      external-declaration (2)
 *      declaration-list (1)(2), only for K&R function definitions
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct declaration
{
  node_kind_t kind;
  struct declaration_specifiers *ds;
  struct init_declarator_list *idl;
  struct static_assert_declaration *sad;
  struct symtable *sym_table;
  void (*create_symtable) (struct declaration * buff);
  void (*create_symbol) (struct declaration * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
