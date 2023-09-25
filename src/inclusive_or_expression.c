#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "inclusive_or_expression.h"
#include "exclusive_or_expression.h"
#include "logical_and_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct inclusive_or_expression *
inclusive_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct inclusive_or_expression *buff =
    calloc (1, sizeof (struct inclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->xor_e = ptr;
  buff->xor_e->parent_kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->xor_e->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct inclusive_or_expression *
inclusive_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct inclusive_or_expression *buff =
    calloc (1, sizeof (struct inclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->or_e = ptr1;
  buff->xor_e = ptr2;
  buff->or_e->parent_kind = buff->xor_e->parent_kind =
    NODE_INCLUSIVE_OR_EXPRESSION;
  buff->or_e->parent = buff->xor_e->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct inclusive_or_expression *node = Node;
  assert (node->kind == NODE_INCLUSIVE_OR_EXPRESSION);
  FILE *f = F;

  if (node->xor_e != NULL && node->or_e == NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->xor_e);
      fprintf (f, "\t%lu [label=\"exclusive-or expression\"]\n",
               (unsigned long) node->xor_e);
      node->xor_e->dot_create (node->xor_e, f);
    }
  else if (node->or_e != NULL && node->xor_e != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->or_e);
      fprintf (f, "\t%lu [label=\"inclusive-or expression\"]\n",
               (unsigned long) node->or_e);
      node->or_e->dot_create (node->or_e, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"|\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->xor_e);
      fprintf (f, "\t%lu [label=\"exclusive-or expression\"]\n",
               (unsigned long) node->xor_e);
      node->xor_e->dot_create (node->xor_e, f);
    }
}
