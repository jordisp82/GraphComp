#include <assert.h>
#include <stdlib.h>

#include "exclusive_or_expression.h"
#include "and_expression.h"
#include "inclusive_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct exclusive_or_expression *
exclusive_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct exclusive_or_expression *buff =
    calloc (1, sizeof (struct exclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->and_e = ptr;
  buff->and_e->parent_kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->and_e->parent = buff;

  return buff;
}

struct exclusive_or_expression *
exclusive_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct exclusive_or_expression *buff =
    calloc (1, sizeof (struct exclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->xor_e = ptr1;
  buff->and_e = ptr2;
  buff->xor_e->parent_kind = buff->and_e->parent_kind =
    NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->xor_e->parent = buff->and_e->parent = buff;

  return buff;
}

void
set_xor_expression_scope (struct exclusive_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXCLUSIVE_OR_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_EXCLUSIVE_OR_EXPRESSION:
        set_xor_expression_scope (buff->parent);
        buff->scope =
          ((struct exclusive_or_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct exclusive_or_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_INCLUSIVE_OR_EXPRESSION:
        set_or_expression_scope (buff->parent);
        buff->scope =
          ((struct inclusive_or_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct inclusive_or_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
