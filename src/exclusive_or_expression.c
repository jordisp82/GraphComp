#include <assert.h>
#include <stdlib.h>

#include "exclusive_or_expression.h"
#include "and_expression.h"
#include "inclusive_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct exclusive_or_expression *
exclusive_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct exclusive_or_expression *buff =
    calloc (1, sizeof (struct exclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->and_e = ptr;
  buff->and_e->parent_kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->and_e->parent = buff;

  return buff;
}

struct exclusive_or_expression *
exclusive_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct exclusive_or_expression *buff =
    calloc (1, sizeof (struct exclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->xor_e = ptr1;
  buff->and_e = ptr2;
  buff->xor_e->parent_kind = buff->and_e->parent_kind =
    NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->xor_e->parent = buff->and_e->parent = buff;

  return buff;
}
