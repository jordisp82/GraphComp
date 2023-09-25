#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "conditional_expression.h"
#include "logical_or_expression.h"
#include "expression.h"
#include "assignment_expression.h"
#include "constant_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct conditional_expression *
conditional_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct conditional_expression *buff =
    calloc (1, sizeof (struct conditional_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr = ptr;
  buff->l_expr->parent_kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct conditional_expression *
conditional_expression_2 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct conditional_expression *buff =
    calloc (1, sizeof (struct conditional_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr = ptr1;
  buff->expr = ptr2;
  buff->cond_e = ptr3;
  buff->l_expr->parent_kind = buff->expr->parent_kind =
    buff->cond_e->parent_kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr->parent = buff->expr->parent = buff->cond_e->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct conditional_expression *node = Node;
  assert (node->kind == NODE_CONDITIONAL_EXPRESSION);
  FILE *f = F;

  if (node->l_expr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->l_expr);
      fprintf (f, "\t%lu [label=\"logical-or expression\"]\n",
               (unsigned long) node->l_expr);
      node->l_expr->dot_create (node->l_expr, f);
    }
  if (node->expr != NULL)
    {
      fprintf (f, "\t%lu -> %lu0\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"?\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->expr);
      fprintf (f, "\t%lu [label=\"expression\"]\n",
               (unsigned long) node->expr);
      node->expr->dot_create (node->expr, f);
    }
  if (node->cond_e != NULL)
    {
      fprintf (f, "\t%lu -> %lu1\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu1 [label=\"?\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->cond_e);
      fprintf (f, "\t%lu [label=\"conditional expression\"]\n",
               (unsigned long) node->cond_e);
      node->cond_e->dot_create (node->cond_e, f);
    }
}
