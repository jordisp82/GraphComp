#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "and_expression.h"
#include "equality_expression.h"
#include "exclusive_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct and_expression *
and_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct and_expression *buff = calloc (1, sizeof (struct and_expression));
  assert (buff != NULL);
  buff->kind = NODE_AND_EXPRESSION;
  buff->eq = ptr;
  buff->eq->parent_kind = NODE_AND_EXPRESSION;
  buff->eq->parent = buff;

  return buff;
}

struct and_expression *
and_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct and_expression *buff = calloc (1, sizeof (struct and_expression));
  assert (buff != NULL);
  buff->kind = NODE_AND_EXPRESSION;
  buff->and_e = ptr1;
  buff->eq = ptr2;
  buff->and_e->parent_kind = buff->eq->parent_kind = NODE_AND_EXPRESSION;
  buff->and_e->parent = buff->eq->parent = buff;

  return buff;
}
