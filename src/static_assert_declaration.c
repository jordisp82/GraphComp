#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "static_assert_declaration.h"
#include "constant_expression.h"
#include "declaration.h"
#include "struct_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct static_assert_declaration *
static_assert_declaration_1 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct static_assert_declaration *buff =
    calloc (1, sizeof (struct static_assert_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STATIC_ASSERT_DECLARATION;
  buff->expr = ptr1;
  buff->str = strdup (str);
  assert (buff->str != NULL);
  buff->expr->parent_kind = NODE_STATIC_ASSERT_DECLARATION;
  buff->expr->parent = buff;

  return buff;
}

void
set_static_assert_scope (struct static_assert_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STATIC_ASSERT_DECLARATION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_DECLARATION:
        set_declaration_scope (buff->parent);
        buff->scope = ((struct declaration *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct declaration *) (buff->parent))->scope_kind;
        break;

      case NODE_STRUCT_DECLARATION:
        set_struct_declaration_scope (buff->parent);
        buff->scope = ((struct struct_declaration *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct struct_declaration *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
