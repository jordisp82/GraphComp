#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "relational_expression.h"
#include "shift_expression.h"
#include "equality_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct relational_expression *
relational_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->sh_ex = ptr;
  buff->sh_ex->parent_kind = NODE_RELATIONAL_EXPRESSION;
  buff->sh_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct relational_expression *
relational_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->relex = ptr1;
  buff->sh_ex = ptr2;
  buff->relex->parent_kind = buff->sh_ex->parent_kind =
    NODE_RELATIONAL_EXPRESSION;
  buff->relex->parent = buff->sh_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct relational_expression *
relational_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->relex = ptr1;
  buff->sh_ex = ptr2;
  buff->relex->parent_kind = buff->sh_ex->parent_kind =
    NODE_RELATIONAL_EXPRESSION;
  buff->relex->parent = buff->sh_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct relational_expression *
relational_expression_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->relex = ptr1;
  buff->sh_ex = ptr2;
  buff->relex->parent_kind = buff->sh_ex->parent_kind =
    NODE_RELATIONAL_EXPRESSION;
  buff->relex->parent = buff->sh_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct relational_expression *
relational_expression_5 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->relex = ptr1;
  buff->sh_ex = ptr2;
  buff->relex->parent_kind = buff->sh_ex->parent_kind =
    NODE_RELATIONAL_EXPRESSION;
  buff->relex->parent = buff->sh_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct relational_expression *node = Node;
  assert (node->kind == NODE_RELATIONAL_EXPRESSION);
  FILE *f = F;

  assert (node->sh_ex != NULL);
  if (node->rel_kind == REL_SHIFT)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sh_ex);
      fprintf (f, "\t%lu [label=\"shift expression\"]\n",
               (unsigned long) node->sh_ex);
      node->sh_ex->dot_create (node->sh_ex, f);
    }
  else
    {
      assert (node->relex != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->relex);
      fprintf (f, "\t%lu [label=\"relational expression\"]\n",
               (unsigned long) node->relex);
      node->relex->dot_create (node->relex, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);

      switch (node->rel_kind)
        {
        case REL_LESS:
          fprintf (f, "\t%lu0 [label=\"<\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        case REL_MORE:
          fprintf (f, "\t%lu0 [label=\">\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        case REL_EQ_LESS:
          fprintf (f, "\t%lu0 [label=\"<=\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        case REL_EQ_MORE:
          fprintf (f, "\t%lu0 [label=\">=\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        default:;              /* BUG! */
        }

      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sh_ex);
      fprintf (f, "\t%lu [label=\"shift expression\"]\n",
               (unsigned long) node->sh_ex);
      node->sh_ex->dot_create (node->sh_ex, f);
    }
}
