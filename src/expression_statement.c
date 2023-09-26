#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "expression_statement.h"
#include "expression.h"
#include "statement.h"
#include "iteration_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct expression_statement *
expression_statement_1 (void)
{
  struct expression_statement *buff =
    calloc (1, sizeof (struct expression_statement));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION_STATEMENT;
  buff->es_kind = ES_EMPTY;

  buff->dot_create = local_dot_create;

  return buff;
}

struct expression_statement *
expression_statement_2 (void *ptr)
{
  struct expression_statement *buff =
    calloc (1, sizeof (struct expression_statement));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION_STATEMENT;
  buff->es_kind = ES_EXPRESSION;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_EXPRESSION_STATEMENT;
  buff->expr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct expression_statement *node = Node;
  assert (node->kind == NODE_EXPRESSION_STATEMENT);
  FILE *f = F;

  if (node->expr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->expr);
      fprintf (f, "\t%lu [label=\"expression\"]\n",
               (unsigned long) node->expr);
      node->expr->dot_create (node->expr, f);
    }
  fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node, (unsigned long) node);
  fprintf (f, "\t%lu0 [label=\";\",shape=box,fontname=Courier]\n",
           (unsigned long) node);
}
