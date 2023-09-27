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
static void do_term (struct unary_operator *node, FILE * f,
                     const char *token, int n_token);

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
      do_term (node, f, "&", 0);
      break;

    case UNOP_STAR:
      do_term (node, f, "*", 0);
      break;

    case UNOP_PLUS:
      do_term (node, f, "+", 0);
      break;

    case UNOP_DASH:
      do_term (node, f, "-", 0);
      break;

    case UNOP_TILDE:
      do_term (node, f, "~", 0);
      break;

    case UNOP_EXCLAMATION:
      do_term (node, f, "!", 0);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct unary_operator *node, FILE * f, const char *token,
         int n_token)
{
  assert (node != NULL);
  assert (f != NULL);
  assert (token != NULL);
  assert (n_token >= 0);

  fprintf (f, "\t%lu -> %lu%d;\n", (unsigned long) node,
           (unsigned long) node, n_token);
  fprintf (f, "\t%lu%d [label=\"%s\",shape=box,fontname=Courier]\n",
           (unsigned long) node, n_token, token);
}
