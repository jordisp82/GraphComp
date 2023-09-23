#include <assert.h>
#include <stdlib.h>

#include "assignment_operator.h"
#include "assignment_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct assignment_operator *
assignment_operator_1 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_EQUAL;

  return buff;
}

struct assignment_operator *
assignment_operator_2 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_MUL_ASS;

  return buff;
}

struct assignment_operator *
assignment_operator_3 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_DIV_ASS;

  return buff;
}

struct assignment_operator *
assignment_operator_4 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_MOD_ASS;

  return buff;
}

struct assignment_operator *
assignment_operator_5 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_ADD_ASS;

  return buff;
}

struct assignment_operator *
assignment_operator_6 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_SUB_ASS;

  return buff;
}

struct assignment_operator *
assignment_operator_7 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_LEFT_ASS;

  return buff;
}

struct assignment_operator *
assignment_operator_8 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_RIGHT_ASS;

  return buff;
}

struct assignment_operator *
assignment_operator_9 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_AND_ASS;

  return buff;
}

struct assignment_operator *
assignment_operator_10 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_XOR_ASS;

  return buff;
}

struct assignment_operator *
assignment_operator_11 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_OR_ASS;

  return buff;
}
