#ifndef STRUCT_OR_UNION_SPECIFIER_H
#define STRUCT_OR_UNION_SPECIFIER_H

/**
 * struct-or-union-specifier:
 *      struct-or-union '{' struct-declaration-list '}'             (1)
 *      struct-or-union IDENTIFIER '{' struct-declaration-list '}'  (2)
 *      struct-or-union IDENTIFIER          (3)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symbol.h"

struct struct_or_union_specifier
{
  node_kind_t kind;
  struct struct_or_union *su;
  const char *tag;
  struct struct_declaration_list *sdl;
  node_kind_t parent_kind;
  void *parent;
};

void sem_struct_union_specifier (struct struct_or_union_specifier *buff);       /* to be removed */
symbol_t *create_symbol_from_sus (struct struct_or_union_specifier *buff);

#endif
