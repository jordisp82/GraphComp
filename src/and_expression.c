#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "and_expression.h"
#include "equality_expression.h"
#include "exclusive_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct and_expression *
and_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct and_expression *buff = calloc (1, sizeof (struct and_expression));
  assert (buff != NULL);
  buff->kind = NODE_AND_EXPRESSION;
  buff->eq = ptr;
  buff->eq->parent_kind = NODE_AND_EXPRESSION;
  buff->eq->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct and_expression *
and_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct and_expression *buff = calloc (1, sizeof (struct and_expression));
  assert (buff != NULL);
  buff->kind = NODE_AND_EXPRESSION;
  buff->and_e = ptr1;
  buff->eq = ptr2;
  buff->and_e->parent_kind = buff->eq->parent_kind = NODE_AND_EXPRESSION;
  buff->and_e->parent = buff->eq->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct and_expression *node = Node;
  assert (node->kind == NODE_AND_EXPRESSION);
  FILE *f = F;

  if (node->eq != NULL && node->and_e == NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->eq);
      fprintf (f, "\t%lu [label=\"equality expression\"]\n",
               (unsigned long) node->eq);
      node->eq->dot_create (node->eq, f);
    }
  else if (node->and_e != NULL && node->eq != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->and_e);
      fprintf (f, "\t%lu [label=\"and expression\"]\n",
               (unsigned long) node->and_e);
      node->and_e->dot_create (node->and_e, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"&\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->eq);
      fprintf (f, "\t%lu [label=\"equality expression\"]\n",
               (unsigned long) node->eq);
      node->eq->dot_create (node->eq, f);
    }
}
