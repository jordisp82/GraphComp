#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "expression.h"
#include "assignment_expression.h"
#include "primary_expression.h"
#include "postfix_expression.h"
#include "conditional_expression.h"
#include "expression_statement.h"
#include "selection_statement.h"
#include "iteration_statement.h"
#include "jump_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct expression *
expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct expression *buff = calloc (1, sizeof (struct expression));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION;
  buff->ass = ptr;
  buff->ass->parent_kind = NODE_EXPRESSION;
  buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct expression *
expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct expression *buff = calloc (1, sizeof (struct expression));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION;
  buff->expr = ptr1;
  buff->ass = ptr2;
  buff->expr->parent_kind = buff->ass->parent_kind = NODE_EXPRESSION;
  buff->expr->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct expression *node = Node;
  assert (node->kind == NODE_EXPRESSION);
  FILE *f = F;

  if (node->ass != NULL && node->expr == NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ass);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) node->ass);
      node->ass->dot_create (node->ass, f);
    }
  else if (node->ass != NULL && node->expr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->expr);
      fprintf (f, "\t%lu [label=\"expression\"]\n",
               (unsigned long) node->expr);
      node->expr->dot_create (node->expr, f);
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\",\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ass);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) node->ass);
      node->ass->dot_create (node->ass, f);
    }
}
