#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "assignment_expression.h"
#include "conditional_expression.h"
#include "unary_expression.h"
#include "assignment_operator.h"
#include "expression.h"
#include "argument_expression_list.h"
#include "initializer.h"
#include "direct_declarator.h"
#include "direct_abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct assignment_expression *
assignment_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct assignment_expression *buff =
    calloc (1, sizeof (struct assignment_expression));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->cond_e = ptr;
  buff->cond_e->parent_kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->cond_e->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct assignment_expression *
assignment_expression_2 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct assignment_expression *buff =
    calloc (1, sizeof (struct assignment_expression));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->un_expr = ptr1;
  buff->ass_op = ptr2;
  buff->ass_e = ptr3;
  buff->un_expr->parent_kind = buff->ass_op->parent_kind =
    buff->ass_e->parent_kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->un_expr->parent = buff->ass_op->parent = buff->ass_e->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct assignment_expression *node = Node;
  assert (node->kind == NODE_ASSIGNMENT_EXPRESSION);
  FILE *f = F;

  if (node->cond_e != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->cond_e);
      fprintf (f, "\t%lu [label=\"conditional expression\"]\n",
               (unsigned long) node->cond_e);
      node->cond_e->dot_create (node->cond_e, f);
    }
  if (node->un_expr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->un_expr);
      fprintf (f, "\t%lu [label=\"unary expression\"]\n",
               (unsigned long) node->un_expr);
      node->un_expr->dot_create (node->un_expr, f);
    }
  if (node->ass_op != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ass_op);
      fprintf (f, "\t%lu [label=\"assignment operator\"]\n",
               (unsigned long) node->ass_op);
      node->ass_op->dot_create (node->ass_op, f);
    }
  if (node->ass_e != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ass_e);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) node->ass_e);
      node->ass_e->dot_create (node->ass_e, f);
    }
}
