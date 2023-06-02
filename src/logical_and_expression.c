#include <assert.h>
#include <stdlib.h>

#include "logical_and_expression.h"
#include "inclusive_or_expression.h"
#include "logical_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct logical_and_expression *
logical_and_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct logical_and_expression *buff =
    calloc (1, sizeof (struct logical_and_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_AND_EXPRESSION;
  buff->inc_or = ptr;
  buff->inc_or->parent_kind = NODE_LOGICAL_AND_EXPRESSION;
  buff->inc_or->parent = buff;

  return buff;
}

struct logical_and_expression *
logical_and_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct logical_and_expression *buff =
    calloc (1, sizeof (struct logical_and_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_AND_EXPRESSION;
  buff->log_and = ptr1;
  buff->inc_or = ptr2;
  buff->log_and->parent_kind = buff->inc_or->parent_kind =
    NODE_LOGICAL_AND_EXPRESSION;
  buff->log_and->parent = buff->inc_or->parent = buff;

  return buff;
}

void
set_logic_and_expression_scope (struct logical_and_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_AND_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_LOGICAL_AND_EXPRESSION:
        set_logic_and_expression_scope (buff->parent);
        buff->scope =
          ((struct logical_and_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct logical_and_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_LOGICAL_OR_EXPRESSION:
        set_logic_or_expression_scope (buff->parent);
        buff->scope =
          ((struct logical_or_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct logical_or_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
