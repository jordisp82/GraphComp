#include <assert.h>
#include <stdlib.h>

#include "cast_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct cast_expression *
cast_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct cast_expression *buff = calloc (1, sizeof (struct cast_expression));
  assert (buff != NULL);
  buff->kind = NODE_CAST_EXPRESSION;
  buff->cast_kind = CAST_NO;
  buff->unary_ex = ptr;

  return buff;
}

struct cast_expression *
cast_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct cast_expression *buff = calloc (1, sizeof (struct cast_expression));
  assert (buff != NULL);
  buff->kind = NODE_CAST_EXPRESSION;
  buff->cast_kind = CAST_NO;
  buff->tn = ptr1;
  buff->unary_ex = ptr2;

  return buff;
}
