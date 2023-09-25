#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "additive_expression.h"
#include "multiplicative_expression.h"
#include "shift_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct additive_expression *
additive_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct additive_expression *buff =
    calloc (1, sizeof (struct additive_expression));
  assert (buff != NULL);
  buff->kind = NODE_ADDITIVE_EXPRESSION;
  buff->add_kind = ADD_NONE;
  buff->mult_ex = ptr;
  buff->mult_ex->parent_kind = NODE_ADDITIVE_EXPRESSION;
  buff->mult_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct additive_expression *
additive_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct additive_expression *buff =
    calloc (1, sizeof (struct additive_expression));
  assert (buff != NULL);
  buff->kind = NODE_ADDITIVE_EXPRESSION;
  buff->add_kind = ADD_PLUS;
  buff->add_ex = ptr1;
  buff->mult_ex = ptr2;
  buff->add_ex->parent_kind = buff->mult_ex->parent_kind =
    NODE_ADDITIVE_EXPRESSION;
  buff->add_ex->parent = buff->mult_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct additive_expression *
additive_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct additive_expression *buff =
    calloc (1, sizeof (struct additive_expression));
  assert (buff != NULL);
  buff->kind = NODE_ADDITIVE_EXPRESSION;
  buff->add_kind = ADD_MINUS;
  buff->add_ex = ptr1;
  buff->mult_ex = ptr2;
  buff->add_ex->parent_kind = buff->mult_ex->parent_kind =
    NODE_ADDITIVE_EXPRESSION;
  buff->add_ex->parent = buff->mult_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct additive_expression *node = Node;
  assert (node->kind == NODE_ADDITIVE_EXPRESSION);
  FILE *f = F;

  assert (node->mult_ex != NULL);
  if (node->add_kind == ADD_NONE)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->mult_ex);
      fprintf (f, "\t%lu [label=\"multiplicative expression\"]\n",
               (unsigned long) node->mult_ex);
      node->mult_ex->dot_create (node->mult_ex, f);
    }
  else
    {
      assert (node->add_ex != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->add_ex);
      fprintf (f, "\t%lu [label=\"additive expression\"]\n",
               (unsigned long) node->add_ex);
      node->add_ex->dot_create (node->add_ex, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);

      switch (node->kind)
        {
        case ADD_PLUS:
          fprintf (f, "\t%lu0 [label=\"+\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        case ADD_MINUS:
          fprintf (f, "\t%lu0 [label=\"-\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        default:;              /* BUG! */
        }

      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->mult_ex);
      fprintf (f, "\t%lu [label=\"multiplicative expression\"]\n",
               (unsigned long) node->mult_ex);
      node->mult_ex->dot_create (node->mult_ex, f);
    }
}
