#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "unary_operator.h"
#include "unary_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct unary_operator *
unary_operator_1 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_AMPERSAND;

  buff->dot_create = local_dot_create;

  return buff;
}

struct unary_operator *
unary_operator_2 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_STAR;

  buff->dot_create = local_dot_create;

  return buff;
}

struct unary_operator *
unary_operator_3 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_PLUS;

  buff->dot_create = local_dot_create;

  return buff;
}

struct unary_operator *
unary_operator_4 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_DASH;

  buff->dot_create = local_dot_create;

  return buff;
}

struct unary_operator *
unary_operator_5 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_TILDE;

  buff->dot_create = local_dot_create;

  return buff;
}

struct unary_operator *
unary_operator_6 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_EXCLAMATION;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct unary_operator *node = Node;
  assert (node->kind == NODE_UNARY_OPERATOR);
  FILE *f = F;

  switch (node->un_op)
    {
    case UNOP_AMPERSAND:
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"&\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case UNOP_STAR:
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"*\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case UNOP_PLUS:
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"+\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case UNOP_DASH:
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"-\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case UNOP_TILDE:
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"~\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    case UNOP_EXCLAMATION:
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"!\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      break;

    default:;                  /* BUG! */
    }
}
