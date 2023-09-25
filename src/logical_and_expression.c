#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "logical_and_expression.h"
#include "inclusive_or_expression.h"
#include "logical_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct logical_and_expression *
logical_and_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct logical_and_expression *buff =
    calloc (1, sizeof (struct logical_and_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_AND_EXPRESSION;
  buff->inc_or = ptr;
  buff->inc_or->parent_kind = NODE_LOGICAL_AND_EXPRESSION;
  buff->inc_or->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct logical_and_expression *
logical_and_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct logical_and_expression *buff =
    calloc (1, sizeof (struct logical_and_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_AND_EXPRESSION;
  buff->log_and = ptr1;
  buff->inc_or = ptr2;
  buff->log_and->parent_kind = buff->inc_or->parent_kind =
    NODE_LOGICAL_AND_EXPRESSION;
  buff->log_and->parent = buff->inc_or->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct logical_and_expression *node = Node;
  assert (node->kind == NODE_LOGICAL_AND_EXPRESSION);
  FILE *f = F;

  if (node->inc_or != NULL && node->log_and == NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->inc_or);
      fprintf (f, "\t%lu [label=\"inclusive-or expression\"]\n",
               (unsigned long) node->inc_or);
      node->inc_or->dot_create (node->inc_or, f);
    }
  else if (node->log_and != NULL && node->inc_or != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->log_and);
      fprintf (f, "\t%lu [label=\"logical-and expression\"]\n",
               (unsigned long) node->log_and);
      node->log_and->dot_create (node->log_and, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"&&\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->inc_or);
      fprintf (f, "\t%lu [label=\"inclusive-or expression\"]\n",
               (unsigned long) node->inc_or);
      node->inc_or->dot_create (node->inc_or, f);
    }
}
