#ifndef STATIC_ASSERT_DECLARATION_H
#define STATIC_ASSERT_DECLARATION_H

/**
 * static_assert-declaration:
 *      STATIC_ASSERT '(' constant-expression ',' STRING_LITERAL ')' ';'
 */

#include "node_kind_t.h"
#include "structs.h"

struct static_assert_declaration
{
  node_kind_t kind;
  struct constant_expression *expr;
  const char *str;
  node_kind_t parent_kind;
  void *parent;
};

#endif
