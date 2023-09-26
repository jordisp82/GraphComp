#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "selection_statement.h"
#include "expression.h"
#include "statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct selection_statement *node, FILE * f,
                     const char *token, int n_token);

struct selection_statement *
selection_statement_1 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct selection_statement *buff =
    calloc (1, sizeof (struct selection_statement));
  assert (buff != NULL);
  buff->kind = NODE_SELECTION_STATEMENT;
  buff->ss_kind = SS_IF_ELSE;
  buff->ex = ptr1;
  buff->st1 = ptr2;
  buff->st2 = ptr3;
  buff->ex->parent_kind = buff->st1->parent_kind = buff->st2->parent_kind =
    NODE_SELECTION_STATEMENT;
  buff->ex->parent = buff->st1->parent = buff->st2->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct selection_statement *
selection_statement_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct selection_statement *buff =
    calloc (1, sizeof (struct selection_statement));
  assert (buff != NULL);
  buff->kind = NODE_SELECTION_STATEMENT;
  buff->ss_kind = SS_IF;
  buff->ex = ptr1;
  buff->st1 = ptr2;
  buff->ex->parent_kind = buff->st1->parent_kind = NODE_SELECTION_STATEMENT;
  buff->ex->parent = buff->st1->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct selection_statement *
selection_statement_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct selection_statement *buff =
    calloc (1, sizeof (struct selection_statement));
  assert (buff != NULL);
  buff->kind = NODE_SELECTION_STATEMENT;
  buff->ss_kind = SS_SWITCH;
  buff->ex = ptr1;
  buff->st1 = ptr2;
  buff->ex->parent_kind = buff->st1->parent_kind = NODE_SELECTION_STATEMENT;
  buff->ex->parent = buff->st1->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct selection_statement *node = Node;
  assert (node->kind == NODE_SELECTION_STATEMENT);
  FILE *f = F;

  if (node->ss_kind == SS_IF_ELSE || node->ss_kind == SS_IF)
    do_term (node, f, "if", 0);
  else if (node->ss_kind == SS_SWITCH)
    do_term (node, f, "switch", 0);
  else
    return;                     /* BUG! */

  do_term (node, f, "(", 1);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->ex);
  fprintf (f, "\t%lu [label=\"expression\"]\n", (unsigned long) node->ex);
  node->ex->dot_create (node->ex, f);
  do_term (node, f, ")", 2);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->st1);
  fprintf (f, "\t%lu [label=\"statement\"]\n", (unsigned long) node->st1);
  node->st1->dot_create (node->st1, f);
  if (node->ss_kind == SS_IF_ELSE)
    {
      do_term (node, f, "else", 3);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->st2);
      fprintf (f, "\t%lu [label=\"statement\"]\n", (unsigned long) node->st2);
      node->st2->dot_create (node->st2, f);
    }
}

static void
do_term (struct selection_statement *node, FILE * f, const char *token,
         int n_token)
{
  assert (node != NULL);
  assert (f != NULL);
  assert (token != NULL);
  assert (n_token >= 0);

  fprintf (f, "\t%lu -> %lu%d;\n", (unsigned long) node,
           (unsigned long) node, n_token);
  fprintf (f, "\t%lu%d [label=\"%s\",shape=box,fontname=Courier]\n",
           (unsigned long) node, n_token, token);
}
