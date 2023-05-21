#ifndef DECLARATION_H
#define DECLARATION_H

/**
 * declaration:
 *      declaration-specifiers ';'              (1)
 *      declaration-specifiers init-declarator-list ';'        (2)
 *      static_assert-declaration               (3)
 */

#include "node_kind_t.h"
#include "structs.h"

struct declaration
{
  node_kind_t kind;
  struct declaration_specifiers *ds;
  struct init_declarator_list *idl;
  struct static_assert_declaration *sad;
  node_kind_t parent_kind;
  void *parent;
};

int look_for_typedef (struct declaration_specifiers *ds);
void register_ids_as_typedef (struct init_declarator_list *idl);

#endif
