#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "inclusive_or_expression.h"
#include "exclusive_or_expression.h"
#include "logical_and_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct inclusive_or_expression *
inclusive_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct inclusive_or_expression *buff =
    calloc (1, sizeof (struct inclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->xor_e = ptr;
  buff->xor_e->parent_kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->xor_e->parent = buff;

  return buff;
}

struct inclusive_or_expression *
inclusive_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct inclusive_or_expression *buff =
    calloc (1, sizeof (struct inclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->or_e = ptr1;
  buff->xor_e = ptr2;
  buff->or_e->parent_kind = buff->xor_e->parent_kind =
    NODE_INCLUSIVE_OR_EXPRESSION;
  buff->or_e->parent = buff->xor_e->parent = buff;

  return buff;
}

