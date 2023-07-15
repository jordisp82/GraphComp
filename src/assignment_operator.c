#include <assert.h>
#include <stdlib.h>

#include "assignment_operator.h"
#include "assignment_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ass_create_symtable (struct assignment_operator *buff);

struct assignment_operator *
assignment_operator_1 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_EQUAL;
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

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
  buff->create_symtable = ass_create_symtable;

  return buff;
}

static void
ass_create_symtable (struct assignment_operator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ASSIGNMENT_OPERATOR);

  buff->sym_table =
    ((struct assignment_expression *) (buff->parent))->sym_table;
}
