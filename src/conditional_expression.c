#include <assert.h>
#include <stdlib.h>

#include "conditional_expression.h"
#include "logical_or_expression.h"
#include "expression.h"
#include "assignment_expression.h"
#include "constant_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct conditional_expression *
conditional_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct conditional_expression *buff =
    calloc (1, sizeof (struct conditional_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr = ptr;
  buff->l_expr->parent_kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr->parent = buff;

  return buff;
}

struct conditional_expression *
conditional_expression_2 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct conditional_expression *buff =
    calloc (1, sizeof (struct conditional_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr = ptr1;
  buff->expr = ptr2;
  buff->cond_e = ptr3;
  buff->l_expr->parent_kind = buff->expr->parent_kind =
    buff->cond_e->parent_kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr->parent = buff->expr->parent = buff->cond_e->parent = buff;

  return buff;
}

void
set_cond_expression_scope (struct conditional_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CONDITIONAL_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_CONDITIONAL_EXPRESSION:
        set_cond_expression_scope (buff->parent);
        buff->scope =
          ((struct conditional_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct conditional_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_ASSIGNMENT_EXPRESSION:
        set_assignment_expression_scope (buff->parent);
        buff->scope =
          ((struct assignment_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct assignment_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_CONSTANT_EXPRESSION:
        set_const_expression_scope (buff->parent);
        buff->scope = ((struct constant_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct constant_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
