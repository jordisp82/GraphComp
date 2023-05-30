#include <assert.h>
#include <stdlib.h>

#include "and_expression.h"
#include "equality_expression.h"
#include "exclusive_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct and_expression *
and_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct and_expression *buff = calloc (1, sizeof (struct and_expression));
  assert (buff != NULL);
  buff->kind = NODE_AND_EXPRESSION;
  buff->eq = ptr;
  buff->eq->parent_kind = NODE_AND_EXPRESSION;
  buff->eq->parent = buff;

  return buff;
}

struct and_expression *
and_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct and_expression *buff = calloc (1, sizeof (struct and_expression));
  assert (buff != NULL);
  buff->kind = NODE_AND_EXPRESSION;
  buff->and_e = ptr1;
  buff->eq = ptr2;
  buff->and_e->parent_kind = buff->eq->parent_kind = NODE_AND_EXPRESSION;
  buff->and_e->parent = buff->eq->parent = buff;

  return buff;
}

void
set_and_expression_scope (struct and_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_AND_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_AND_EXPRESSION:
      set_and_expression_scope (buff->parent);
      buff->scope = ((struct and_expression *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct and_expression *) (buff->parent))->scope_kind;
      break;

    case NODE_EXCLUSIVE_OR_EXPRESSION:
      set_xor_expression_scope (buff->parent);
      buff->scope =
        ((struct exclusive_or_expression *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct exclusive_or_expression *) (buff->parent))->scope_kind;
      break;

    default:
      ;                         /* BUG! */
    }
}
