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
