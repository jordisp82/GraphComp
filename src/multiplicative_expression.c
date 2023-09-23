#include <assert.h>
#include <stdlib.h>

#include "multiplicative_expression.h"
#include "cast_expression.h"
#include "additive_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct multiplicative_expression *
multiplicative_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_NONE;
  buff->cast_ex = ptr;
  buff->cast_ex->parent_kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->cast_ex->parent = buff;

  return buff;
}

struct multiplicative_expression *
multiplicative_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_STAR;
  buff->mult_ex = ptr1;
  buff->cast_ex = ptr2;
  buff->mult_ex->parent_kind = buff->cast_ex->parent_kind =
    NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_ex->parent = buff->cast_ex->parent = buff;

  return buff;
}

struct multiplicative_expression *
multiplicative_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_SLASH;
  buff->mult_ex = ptr1;
  buff->cast_ex = ptr2;
  buff->mult_ex->parent_kind = buff->cast_ex->parent_kind =
    NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_ex->parent = buff->cast_ex->parent = buff;

  return buff;
}

struct multiplicative_expression *
multiplicative_expression_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_MODULO;
  buff->mult_ex = ptr1;
  buff->cast_ex = ptr2;
  buff->mult_ex->parent_kind = buff->cast_ex->parent_kind =
    NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_ex->parent = buff->cast_ex->parent = buff;

  return buff;
}
