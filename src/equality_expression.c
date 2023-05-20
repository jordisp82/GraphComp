#include <assert.h>
#include <stdlib.h>

#include "equality_expression.h"
#include "relational_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct equality_expression *
equality_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct equality_expression *buff =
    calloc (1, sizeof (struct equality_expression));
  assert (buff != NULL);
  buff->kind = NODE_EQUALITY_EXPRESSION;
  buff->eq_kind = EQ_NO_OP;
  buff->rexp = ptr;
  buff->rexp->parent_kind = NODE_EQUALITY_EXPRESSION;
  buff->rexp->parent = buff;

  return buff;
}

struct equality_expression *
equality_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct equality_expression *buff =
    calloc (1, sizeof (struct equality_expression));
  assert (buff != NULL);
  buff->kind = NODE_EQUALITY_EXPRESSION;
  buff->eq_kind = EQ_EQUAL;
  buff->eqex = ptr1;
  buff->rexp = ptr2;
  buff->eqex->parent_kind = buff->rexp->parent_kind =
    NODE_EQUALITY_EXPRESSION;
  buff->eqex->parent = buff->rexp->parent = buff;

  return buff;
}

struct equality_expression *
equality_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct equality_expression *buff =
    calloc (1, sizeof (struct equality_expression));
  assert (buff != NULL);
  buff->kind = NODE_EQUALITY_EXPRESSION;
  buff->eq_kind = EQ_NOT_EQUAL;
  buff->eqex = ptr1;
  buff->rexp = ptr2;
  buff->eqex->parent_kind = buff->rexp->parent_kind =
    NODE_EQUALITY_EXPRESSION;
  buff->eqex->parent = buff->rexp->parent = buff;

  return buff;
}
