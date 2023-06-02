#include <assert.h>
#include <stdlib.h>

#include "inclusive_or_expression.h"
#include "exclusive_or_expression.h"
#include "logical_and_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct inclusive_or_expression *
inclusive_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct inclusive_or_expression *buff =
    calloc (1, sizeof (struct inclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->xor_e = ptr;
  buff->xor_e->parent_kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->xor_e->parent = buff;

  return buff;
}

struct inclusive_or_expression *
inclusive_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct inclusive_or_expression *buff =
    calloc (1, sizeof (struct inclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->or_e = ptr1;
  buff->xor_e = ptr2;
  buff->or_e->parent_kind = buff->xor_e->parent_kind =
    NODE_INCLUSIVE_OR_EXPRESSION;
  buff->or_e->parent = buff->xor_e->parent = buff;

  return buff;
}

void
set_or_expression_scope (struct inclusive_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INCLUSIVE_OR_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_INCLUSIVE_OR_EXPRESSION:
        set_or_expression_scope (buff->parent);
        buff->scope =
          ((struct inclusive_or_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct inclusive_or_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_LOGICAL_AND_EXPRESSION:
        set_logic_and_expression_scope (buff->parent);
        buff->scope =
          ((struct logical_and_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct logical_and_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
