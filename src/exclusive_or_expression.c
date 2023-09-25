#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "exclusive_or_expression.h"
#include "and_expression.h"
#include "inclusive_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct exclusive_or_expression *
exclusive_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct exclusive_or_expression *buff =
    calloc (1, sizeof (struct exclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->and_e = ptr;
  buff->and_e->parent_kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->and_e->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct exclusive_or_expression *
exclusive_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct exclusive_or_expression *buff =
    calloc (1, sizeof (struct exclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->xor_e = ptr1;
  buff->and_e = ptr2;
  buff->xor_e->parent_kind = buff->and_e->parent_kind =
    NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->xor_e->parent = buff->and_e->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct exclusive_or_expression *node = Node;
  assert (node->kind == NODE_EXCLUSIVE_OR_EXPRESSION);
  FILE *f = F;

  if (node->and_e != NULL && node->xor_e == NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->and_e);
      fprintf (f, "\t%lu [label=\"and expression\"]\n",
               (unsigned long) node->and_e);
      node->and_e->dot_create (node->and_e, f);
    }
  else if (node->xor_e != NULL && node->and_e != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->xor_e);
      fprintf (f, "\t%lu [label=\"exclusive-or expression\"]\n",
               (unsigned long) node->xor_e);
      node->xor_e->dot_create (node->xor_e, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"^\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->and_e);
      fprintf (f, "\t%lu [label=\"and expression\"]\n",
               (unsigned long) node->and_e);
      node->and_e->dot_create (node->and_e, f);
    }
}
