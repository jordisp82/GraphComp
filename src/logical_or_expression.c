#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

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
