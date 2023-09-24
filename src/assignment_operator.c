#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "assignment_operator.h"
#include "assignment_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct assignment_operator *
assignment_operator_1 (void)
{
  struct assignment_operator *buff =
    calloc (1, sizeof (struct assignment_operator));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_OPERATOR;
  buff->ass_op = OP_EQUAL;

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct assignment_operator *node = Node;
  assert (node->kind == NODE_ASSIGNMENT_OPERATOR);
  FILE *f = F;

  fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node, (unsigned long) node);

  switch (node->ass_op)
    {
    case OP_EQUAL:
      fprintf (f, "\t%lu0 [label=\"=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_MUL_ASS:
      fprintf (f, "\t%lu0 [label=\"*=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_DIV_ASS:
      fprintf (f, "\t%lu0 [label=\"/=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_MOD_ASS:
      fprintf (f, "\t%lu0 [label=\"%%=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_ADD_ASS:
      fprintf (f, "\t%lu0 [label=\"+=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_SUB_ASS:
      fprintf (f, "\t%lu0 [label=\"-=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_LEFT_ASS:
      fprintf (f, "\t%lu0 [label=\"<<=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_RIGHT_ASS:
      fprintf (f, "\t%lu0 [label=\">>=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_AND_ASS:
      fprintf (f, "\t%lu0 [label=\"&=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_XOR_ASS:
      fprintf (f, "\t%lu0 [label=\"^=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case OP_OR_ASS:
      fprintf (f, "\t%lu0 [label=\"|=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    default:;                  /* BUG! */
    }
}
