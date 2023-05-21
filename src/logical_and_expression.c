#include <assert.h>
#include <stdlib.h>

#include "logical_and_expression.h"
#include "inclusive_or_expression.h"

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
