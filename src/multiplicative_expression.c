#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "multiplicative_expression.h"
#include "cast_expression.h"
#include "additive_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct multiplicative_expression *
multiplicative_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_NONE;
  buff->cast_ex = ptr;
  buff->cast_ex->parent_kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->cast_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct multiplicative_expression *
multiplicative_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_STAR;
  buff->mult_ex = ptr1;
  buff->cast_ex = ptr2;
  buff->mult_ex->parent_kind = buff->cast_ex->parent_kind =
    NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_ex->parent = buff->cast_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct multiplicative_expression *
multiplicative_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_SLASH;
  buff->mult_ex = ptr1;
  buff->cast_ex = ptr2;
  buff->mult_ex->parent_kind = buff->cast_ex->parent_kind =
    NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_ex->parent = buff->cast_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct multiplicative_expression *
multiplicative_expression_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_MODULO;
  buff->mult_ex = ptr1;
  buff->cast_ex = ptr2;
  buff->mult_ex->parent_kind = buff->cast_ex->parent_kind =
    NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_ex->parent = buff->cast_ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct multiplicative_expression *node = Node;
  assert (node->kind == NODE_MULTIPLICATIVE_EXPRESSION);
  FILE *f = F;

  assert (node->cast_ex != NULL);
  if (node->mult_kind == MULT_NONE)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->cast_ex);
      fprintf (f, "\t%lu [label=\"cast expression\"]\n",
               (unsigned long) node->cast_ex);
      node->cast_ex->dot_create (node->cast_ex, f);
    }
  else
    {
      assert (node->mult_ex != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->mult_ex);
      fprintf (f, "\t%lu [label=\"multiplicative expression\"]\n",
               (unsigned long) node->mult_ex);
      node->mult_ex->dot_create (node->mult_ex, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);

      switch (node->mult_kind)
        {
        case MULT_STAR:
          fprintf (f, "\t%lu0 [label=\"*\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        case MULT_SLASH:
          fprintf (f, "\t%lu0 [label=\"/\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        case MULT_MODULO:
          fprintf (f, "\t%lu0 [label=\"%%\",shape=box,fontname=Courier]\n",
                   (unsigned long) node);
          break;

        default:;              /* BUG! */
        }

      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->cast_ex);
      fprintf (f, "\t%lu [label=\"cast expression\"]\n",
               (unsigned long) node->cast_ex);
      node->cast_ex->dot_create (node->cast_ex, f);
    }
}
