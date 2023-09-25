#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "logical_or_expression.h"
#include "logical_and_expression.h"
#include "conditional_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct logical_or_expression *
logical_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct logical_or_expression *buff =
    calloc (1, sizeof (struct logical_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_OR_EXPRESSION;
  buff->and_e = ptr;
  buff->and_e->parent_kind = NODE_LOGICAL_OR_EXPRESSION;
  buff->and_e->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct logical_or_expression *
logical_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct logical_or_expression *buff =
    calloc (1, sizeof (struct logical_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_OR_EXPRESSION;
  buff->or_e = ptr1;
  buff->and_e = ptr2;
  buff->or_e->parent_kind = buff->and_e->parent_kind =
    NODE_LOGICAL_OR_EXPRESSION;
  buff->or_e->parent = buff->and_e->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct logical_or_expression *node = Node;
  assert (node->kind == NODE_LOGICAL_OR_EXPRESSION);
  FILE *f = F;

  if (node->and_e != NULL && node->or_e == NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->and_e);
      fprintf (f, "\t%lu [label=\"logical-and expression\"]\n",
               (unsigned long) node->and_e);
      node->and_e->dot_create (node->and_e, f);
    }
  else if (node->or_e != NULL && node->and_e != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->or_e);
      fprintf (f, "\t%lu [label=\"logical-or expression\"]\n",
               (unsigned long) node->or_e);
      node->or_e->dot_create (node->or_e, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"||\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->and_e);
      fprintf (f, "\t%lu [label=\"logical-and expression\"]\n",
               (unsigned long) node->and_e);
      node->and_e->dot_create (node->and_e, f);
    }
}
