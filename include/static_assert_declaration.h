#ifndef STATIC_ASSERT_DECLARATION_H
#define STATIC_ASSERT_DECLARATION_H

/**
 * static_assert-declaration:
 *      STATIC_ASSERT '(' constant-expression ',' STRING_LITERAL ')' ';'
 * 
 * parents:
 *      declaration (3)
 *      struct-declaration (3)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct static_assert_declaration
{
  node_kind_t kind;
  struct constant_expression *expr;
  const char *str;
  struct symtable *sym_table;
  void (*create_symtable) (struct static_assert_declaration * buff);
  void (*create_symbol) (struct static_assert_declaration * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
