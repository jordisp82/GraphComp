#ifndef STRUCT_DECLARATION_H
#define STRUCT_DECLARATION_H

/**
 * struct-declaration:
 *      specifier-qualifier-list ';'            (1)
 *      specifier-qualifier-list struct-declarator-list ';'     (2)
 *      static_assert-declaration               (3)
 * 
 * parents:
 *      struct-declaration-list (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct struct_declaration
{
  node_kind_t kind;
  struct specifier_qualifier_list *sql;
  struct struct_declarator_list *sdl;
  struct static_assert_declaration *sad;
  node_kind_t parent_kind;
  void *parent;
};

#endif
