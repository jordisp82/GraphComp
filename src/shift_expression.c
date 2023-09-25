#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "shift_expression.h"
#include "additive_expression.h"
#include "relational_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct shift_expression *
shift_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct shift_expression *buff =
    calloc (1, sizeof (struct shift_expression));
  assert (buff != NULL);
  buff->kind = NODE_SHIFT_EXPRESSION;
  buff->sh_kind = SHIFT_NONE;
  buff->add_ex = ptr;
  buff->add_ex->parent_kind = NODE_SHIFT_EXPRESSION;
  buff->add_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct shift_expression *
shift_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct shift_expression *buff =
    calloc (1, sizeof (struct shift_expression));
  assert (buff != NULL);
  buff->kind = NODE_SHIFT_EXPRESSION;
  buff->sh_kind = SHIFT_LEFT;
  buff->sh_ex = ptr1;
  buff->add_ex = ptr2;
  buff->sh_ex->parent_kind = buff->add_ex->parent_kind =
    NODE_SHIFT_EXPRESSION;
  buff->sh_ex->parent = buff->add_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct shift_expression *
shift_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct shift_expression *buff =
    calloc (1, sizeof (struct shift_expression));
  assert (buff != NULL);
  buff->kind = NODE_SHIFT_EXPRESSION;
  buff->sh_kind = SHIFT_RIGHT;
  buff->sh_ex = ptr1;
  buff->add_ex = ptr2;
  buff->sh_ex->parent_kind = buff->add_ex->parent_kind =
    NODE_SHIFT_EXPRESSION;
  buff->sh_ex->parent = buff->add_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct shift_expression *node = Node;
  assert (node->kind == NODE_SHIFT_EXPRESSION);
  FILE *f = F;

  assert (node->add_ex != NULL);
  if (node->sh_kind == SHIFT_NONE)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->add_ex);
      fprintf (f, "\t%lu [label=\"additive expression\"]\n",
               (unsigned long) node->add_ex);
      node->add_ex->dot_create (node->add_ex, f);
    }
  else
    {
      assert (node->sh_ex != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sh_ex);
      fprintf (f, "\t%lu [label=\"shift expression\"]\n",
               (unsigned long) node->sh_ex);
      node->sh_ex->dot_create (node->sh_ex, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);

      switch (node->sh_kind)
        {
        case SHIFT_LEFT:
          fprintf (f, "\t%lu0 [label=\"<<\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        case SHIFT_RIGHT:
          fprintf (f, "\t%lu0 [label=\">>\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        default:;              /* BUG! */
        }

      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->add_ex);
      fprintf (f, "\t%lu [label=\"additive expression\"]\n",
               (unsigned long) node->add_ex);
      node->add_ex->dot_create (node->add_ex, f);
    }
}
