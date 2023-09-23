#include <assert.h>
#include <stdlib.h>

#include "shift_expression.h"
#include "additive_expression.h"
#include "relational_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct shift_expression *
shift_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct shift_expression *buff =
    calloc (1, sizeof (struct shift_expression));
  assert (buff != NULL);
  buff->kind = NODE_SHIFT_EXPRESSION;
  buff->sh_kind = SHIFT_NONE;
  buff->add_ex = ptr;
  buff->add_ex->parent_kind = NODE_SHIFT_EXPRESSION;
  buff->add_ex->parent = buff;

  return buff;
}

struct shift_expression *
shift_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct shift_expression *buff =
    calloc (1, sizeof (struct shift_expression));
  assert (buff != NULL);
  buff->kind = NODE_SHIFT_EXPRESSION;
  buff->sh_kind = SHIFT_LEFT;
  buff->sh_ex = ptr1;
  buff->add_ex = ptr2;
  buff->sh_ex->parent_kind = buff->add_ex->parent_kind =
    NODE_SHIFT_EXPRESSION;
  buff->sh_ex->parent = buff->add_ex->parent = buff;

  return buff;
}

struct shift_expression *
shift_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct shift_expression *buff =
    calloc (1, sizeof (struct shift_expression));
  assert (buff != NULL);
  buff->kind = NODE_SHIFT_EXPRESSION;
  buff->sh_kind = SHIFT_RIGHT;
  buff->sh_ex = ptr1;
  buff->add_ex = ptr2;
  buff->sh_ex->parent_kind = buff->add_ex->parent_kind =
    NODE_SHIFT_EXPRESSION;
  buff->sh_ex->parent = buff->add_ex->parent = buff;

  return buff;
}
