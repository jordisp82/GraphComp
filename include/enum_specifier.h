#ifndef ENUM_SPECIFIER_H
#define ENUM_SPECIFIER_H

/**
 * enum-specifier:
 *      ENUM '{' enumerator-list '}'                (1)
 *      ENUM '{' enumerator-list ',' '}'            (2)
 *      ENUM IDENTIFIER '{' enumerator-list '}'     (3)
 *      ENUM IDENTIFIER '{' enumerator-list ',' '}' (4)
 *      ENUM IDENTIFIER         (5)
 * 
 * parents:
 *      type-specifier (15)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symbol.h"

struct enum_specifier
{
  node_kind_t kind;
  const char *tag;
  struct enumerator_list *el;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

symbol_t *create_symbol_from_enum_specifier (struct enum_specifier *buff);
void set_enum_specifier_scope (struct enum_specifier *buff);

#endif
