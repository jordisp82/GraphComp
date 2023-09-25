#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "equality_expression.h"
#include "relational_expression.h"
#include "and_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct equality_expression *
equality_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct equality_expression *buff =
    calloc (1, sizeof (struct equality_expression));
  assert (buff != NULL);
  buff->kind = NODE_EQUALITY_EXPRESSION;
  buff->eq_kind = EQ_NO_OP;
  buff->rexp = ptr;
  buff->rexp->parent_kind = NODE_EQUALITY_EXPRESSION;
  buff->rexp->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct equality_expression *
equality_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct equality_expression *buff =
    calloc (1, sizeof (struct equality_expression));
  assert (buff != NULL);
  buff->kind = NODE_EQUALITY_EXPRESSION;
  buff->eq_kind = EQ_EQUAL;
  buff->eqex = ptr1;
  buff->rexp = ptr2;
  buff->eqex->parent_kind = buff->rexp->parent_kind =
    NODE_EQUALITY_EXPRESSION;
  buff->eqex->parent = buff->rexp->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct equality_expression *
equality_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct equality_expression *buff =
    calloc (1, sizeof (struct equality_expression));
  assert (buff != NULL);
  buff->kind = NODE_EQUALITY_EXPRESSION;
  buff->eq_kind = EQ_NOT_EQUAL;
  buff->eqex = ptr1;
  buff->rexp = ptr2;
  buff->eqex->parent_kind = buff->rexp->parent_kind =
    NODE_EQUALITY_EXPRESSION;
  buff->eqex->parent = buff->rexp->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct equality_expression *node = Node;
  assert (node->kind == NODE_EQUALITY_EXPRESSION);
  FILE *f = F;

  switch (node->eq_kind)
    {
    case EQ_NO_OP:
      assert (node->rexp != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->rexp);
      fprintf (f, "\t%lu [label=\"relational expression\"]\n",
               (unsigned long) node->rexp);
      node->rexp->dot_create (node->rexp, f);
      break;

    case EQ_EQUAL:
    case EQ_NOT_EQUAL:
      assert (node->eqex != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->eqex);
      fprintf (f, "\t%lu [label=\"equality expression\"]\n",
               (unsigned long) node->eqex);
      node->eqex->dot_create (node->eqex, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"%s\",shape=box,fontname=Courier]\n",
               (unsigned long) node,
               (node->eq_kind == EQ_EQUAL ? "==" :
                (node->eq_kind == EQ_NOT_EQUAL ? "!=" : NULL)));
      assert (node->rexp != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->rexp);
      fprintf (f, "\t%lu [label=\"relational expression\"]\n",
               (unsigned long) node->rexp);
      node->rexp->dot_create (node->rexp, f);

    default:;                  /* BUG! */
    }
}
