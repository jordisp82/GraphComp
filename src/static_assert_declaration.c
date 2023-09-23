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
