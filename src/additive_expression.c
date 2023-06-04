#include <assert.h>
#include <stdlib.h>

#include "additive_expression.h"
#include "multiplicative_expression.h"
#include "shift_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct additive_expression *
additive_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct additive_expression *buff =
    calloc (1, sizeof (struct additive_expression));
  assert (buff != NULL);
  buff->kind = NODE_ADDITIVE_EXPRESSION;
  buff->add_kind = ADD_NONE;
  buff->mult_ex = ptr;
  buff->mult_ex->parent_kind = NODE_ADDITIVE_EXPRESSION;
  buff->mult_ex->parent = buff;

  return buff;
}

struct additive_expression *
additive_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct additive_expression *buff =
    calloc (1, sizeof (struct additive_expression));
  assert (buff != NULL);
  buff->kind = NODE_ADDITIVE_EXPRESSION;
  buff->add_kind = ADD_PLUS;
  buff->add_ex = ptr1;
  buff->mult_ex = ptr2;
  buff->add_ex->parent_kind = buff->mult_ex->parent_kind =
    NODE_ADDITIVE_EXPRESSION;
  buff->add_ex->parent = buff->mult_ex->parent = buff;

  return buff;
}

struct additive_expression *
additive_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct additive_expression *buff =
    calloc (1, sizeof (struct additive_expression));
  assert (buff != NULL);
  buff->kind = NODE_ADDITIVE_EXPRESSION;
  buff->add_kind = ADD_MINUS;
  buff->add_ex = ptr1;
  buff->mult_ex = ptr2;
  buff->add_ex->parent_kind = buff->mult_ex->parent_kind =
    NODE_ADDITIVE_EXPRESSION;
  buff->add_ex->parent = buff->mult_ex->parent = buff;

  return buff;
}

void
set_add_expression_scope (struct additive_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ADDITIVE_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_ADDITIVE_EXPRESSION:
        set_add_expression_scope (buff->parent);
        buff->scope = ((struct additive_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct additive_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_SHIFT_EXPRESSION:
        set_shift_expression_scope (buff->parent);
        buff->scope = ((struct shift_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct shift_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
fill_in_symtable_add_expr (struct additive_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ADDITIVE_EXPRESSION);
  assert (buff->mult_ex != NULL);

  fill_in_symtable_mult_expr (buff->mult_ex);
  if (buff->add_ex != NULL)
    fill_in_symtable_add_expr (buff->add_ex);
}
