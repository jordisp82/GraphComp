#include <assert.h>
#include <stdlib.h>

#include "unary_operator.h"
#include "unary_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct unary_operator *
unary_operator_1 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_AMPERSAND;

  return buff;
}

struct unary_operator *
unary_operator_2 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_STAR;

  return buff;
}

struct unary_operator *
unary_operator_3 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_PLUS;

  return buff;
}

struct unary_operator *
unary_operator_4 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_DASH;

  return buff;
}

struct unary_operator *
unary_operator_5 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_TILDE;

  return buff;
}

struct unary_operator *
unary_operator_6 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_EXCLAMATION;

  return buff;
}
