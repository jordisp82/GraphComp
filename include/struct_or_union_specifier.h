#ifndef STRUCT_OR_UNION_SPECIFIER_H
#define STRUCT_OR_UNION_SPECIFIER_H

/**
 * struct-or-union-specifier:
 *      struct-or-union '{' struct-declaration-list '}'             (1)
 *      struct-or-union IDENTIFIER '{' struct-declaration-list '}'  (2)
 *      struct-or-union IDENTIFIER          (3)
 * 
 * parents:
 *      type-specifier (14)
 */

#include "node_kind_t.h"
#include "structs.h"

struct struct_or_union_specifier
{
  node_kind_t kind;
  struct struct_or_union *su;
  const char *tag;
  struct struct_declaration_list *sdl;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
