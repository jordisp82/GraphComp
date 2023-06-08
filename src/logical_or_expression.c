#include <assert.h>
#include <stdlib.h>

#include "logical_or_expression.h"
#include "logical_and_expression.h"
#include "conditional_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct logical_or_expression *
logical_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct logical_or_expression *buff =
    calloc (1, sizeof (struct logical_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_OR_EXPRESSION;
  buff->and_e = ptr;
  buff->and_e->parent_kind = NODE_LOGICAL_OR_EXPRESSION;
  buff->and_e->parent = buff;

  return buff;
}

struct logical_or_expression *
logical_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct logical_or_expression *buff =
    calloc (1, sizeof (struct logical_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_OR_EXPRESSION;
  buff->or_e = ptr1;
  buff->and_e = ptr2;
  buff->or_e->parent_kind = buff->and_e->parent_kind =
    NODE_LOGICAL_OR_EXPRESSION;
  buff->or_e->parent = buff->and_e->parent = buff;

  return buff;
}

void
set_logic_or_expression_scope (struct logical_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_OR_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_LOGICAL_OR_EXPRESSION:
        set_logic_or_expression_scope (buff->parent);
        buff->scope =
          ((struct logical_or_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct logical_or_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_CONDITIONAL_EXPRESSION:
        set_cond_expression_scope (buff->parent);
        buff->scope =
          ((struct conditional_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct conditional_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_logic_or_expression (struct logical_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_OR_EXPRESSION);
  assert (buff->and_e != NULL);

  set_symbol_for_logic_and_expression (buff->and_e);
  if (buff->or_e != NULL)
    set_symbol_for_logic_or_expression (buff->or_e);
}
