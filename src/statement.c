#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "statement.h"
#include "labeled_statement.h"
#include "compound_statement.h"
#include "expression_statement.h"
#include "selection_statement.h"
#include "iteration_statement.h"
#include "jump_statement.h"
#include "block_item.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct statement *
statement_1 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_LABELED_STATEMENT;
  buff->ls = ptr;
  buff->ls->parent_kind = NODE_STATEMENT;
  buff->ls->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct statement *
statement_2 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_COMPOUND_STATEMENT;
  buff->cs = ptr;
  buff->cs->parent_kind = NODE_STATEMENT;
  buff->cs->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct statement *
statement_3 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_EXPRESSION_STATEMENT;
  buff->es = ptr;
  buff->es->parent_kind = NODE_STATEMENT;
  buff->es->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct statement *
statement_4 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_SELECTION_STATEMENT;
  buff->ss = ptr;
  buff->ss->parent_kind = NODE_STATEMENT;
  buff->ss->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct statement *
statement_5 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_ITERATION_STATEMENT;
  buff->is = ptr;
  buff->is->parent_kind = NODE_STATEMENT;
  buff->is->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct statement *
statement_6 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_JUMP_STATEMENT;
  buff->js = ptr;
  buff->js->parent_kind = NODE_STATEMENT;
  buff->js->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct statement *node = Node;
  assert (node->kind == NODE_STATEMENT);
  FILE *f = F;

  switch (node->child_kind)
    {
    case NODE_LABELED_STATEMENT:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ls);
      fprintf (f, "\t%lu [label=\"labeled statement\"]\n",
               (unsigned long) node->ls);
      node->ls->dot_create (node->ls, f);
      break;

    case NODE_COMPOUND_STATEMENT:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->cs);
      fprintf (f, "\t%lu [label=\"compount statement\"]\n",
               (unsigned long) node->cs);
      node->cs->dot_create (node->cs, f);
      break;

    case NODE_EXPRESSION_STATEMENT:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->es);
      fprintf (f, "\t%lu [label=\"expression statement\"]\n",
               (unsigned long) node->es);
      node->es->dot_create (node->es, f);
      break;

    case NODE_SELECTION_STATEMENT:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ss);
      fprintf (f, "\t%lu [label=\"selection statement\"]\n",
               (unsigned long) node->ss);
      node->ss->dot_create (node->ss, f);
      break;

    case NODE_ITERATION_STATEMENT:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is);
      fprintf (f, "\t%lu [label=\"iteration statement\"]\n",
               (unsigned long) node->is);
      node->is->dot_create (node->is, f);
      break;

    case NODE_JUMP_STATEMENT:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->js);
      fprintf (f, "\t%lu [label=\"jump statement\"]\n",
               (unsigned long) node->js);
      node->js->dot_create (node->js, f);
      break;

    default:;                  /* BUG! */
    }
}
