#include <assert.h>
#include <stdlib.h>

#include "assignment_expression.h"
#include "conditional_expression.h"
#include "unary_expression.h"
#include "assignment_operator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct assignment_expression *
assignment_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct assignment_expression *buff =
    calloc (1, sizeof (struct assignment_expression));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->cond_e = ptr;
  buff->cond_e->parent_kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->cond_e->parent = buff;

  return buff;
}

struct assignment_expression *
assignment_expression_2 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct assignment_expression *buff =
    calloc (1, sizeof (struct assignment_expression));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->un_expr = ptr1;
  buff->ass_op = ptr2;
  buff->ass_e = ptr3;
  buff->un_expr->parent_kind = buff->ass_op->parent_kind =
    buff->ass_e->parent_kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->un_expr->parent = buff->ass_op->parent = buff->ass_e->parent = buff;

  return buff;
}
