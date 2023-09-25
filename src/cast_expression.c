#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "cast_expression.h"
#include "unary_expression.h"
#include "type_name.h"
#include "multiplicative_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct cast_expression *
cast_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct cast_expression *buff = calloc (1, sizeof (struct cast_expression));
  assert (buff != NULL);
  buff->kind = NODE_CAST_EXPRESSION;
  buff->cast_kind = CAST_NO;
  buff->unary_ex = ptr;
  buff->unary_ex->parent_kind = NODE_CAST_EXPRESSION;
  buff->unary_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct cast_expression *
cast_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct cast_expression *buff = calloc (1, sizeof (struct cast_expression));
  assert (buff != NULL);
  buff->kind = NODE_CAST_EXPRESSION;
  buff->cast_kind = CAST_NO;
  buff->tn = ptr1;
  buff->cast_ex = ptr2;
  buff->tn->parent_kind = buff->unary_ex->parent_kind = NODE_CAST_EXPRESSION;
  buff->tn->parent = buff->unary_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct cast_expression *node = Node;
  assert (node->kind == NODE_CAST_EXPRESSION);
  FILE *f = F;

  if (node->unary_ex != NULL && node->tn == NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->unary_ex);
      fprintf (f, "\t%lu [label=\"unary expression\"]\n",
               (unsigned long) node->unary_ex);
      node->unary_ex->dot_create (node->unary_ex, f);
    }
  else if (node->cast_ex != NULL && node->tn != NULL)
    {
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"(\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->tn);
      fprintf (f, "\t%lu [label=\"typename\"]\n", (unsigned long) node->tn);
      fprintf (f, "\t%lu -> %lu1;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu1 [label=\")\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->cast_ex);
      fprintf (f, "\t%lu [label=\"cast expression\"]\n",
               (unsigned long) node->cast_ex);
      node->cast_ex->dot_create (node->cast_ex, f);
    }
}
