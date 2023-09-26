#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labeled_statement.h"
#include "statement.h"
#include "constant_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct labeled_statement *node, FILE * f,
                     const char *token, int n_token);

struct labeled_statement *
labeled_statement_1 (const char *str, void *ptr2)
{
  assert (str != NULL);
  assert (ptr2 != NULL);

  struct labeled_statement *buff =
    calloc (1, sizeof (struct labeled_statement));
  assert (buff != NULL);
  buff->kind = NODE_LABELED_STATEMENT;
  buff->ls_kind = LABEL_IDENTIFIER;
  buff->id = strdup (str);
  assert (buff->id != NULL);
  buff->s = ptr2;
  buff->s->parent_kind = NODE_LABELED_STATEMENT;
  buff->s->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct labeled_statement *
labeled_statement_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct labeled_statement *buff =
    calloc (1, sizeof (struct labeled_statement));
  assert (buff != NULL);
  buff->kind = NODE_LABELED_STATEMENT;
  buff->ls_kind = LABEL_CASE;
  buff->ce = ptr1;
  buff->s = ptr2;
  buff->ce->parent_kind = buff->s->parent_kind = NODE_LABELED_STATEMENT;
  buff->ce->parent = buff->s->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct labeled_statement *
labeled_statement_3 (void *ptr)
{
  assert (ptr != NULL);

  struct labeled_statement *buff =
    calloc (1, sizeof (struct labeled_statement));
  assert (buff != NULL);
  buff->kind = NODE_LABELED_STATEMENT;
  buff->ls_kind = LABEL_DEFAULT;
  buff->s = ptr;
  buff->s->parent_kind = NODE_LABELED_STATEMENT;
  buff->s->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct labeled_statement *node = Node;
  assert (node->kind == NODE_LABELED_STATEMENT);
  FILE *f = F;

  switch (node->ls_kind)
    {
    case LABEL_IDENTIFIER:
      do_term (node, f, node->id, 0);
      do_term (node, f, ":", 1);
      fprintf (f, "\%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->s);
      fprintf (f, "\%lu [label=\"statement\"]\n", (unsigned long) node->s);
      node->s->dot_create (node->s, f);
      break;

    case LABEL_CASE:
      do_term (node, f, "case", 0);
      fprintf (f, "\%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ce);
      fprintf (f, "\%lu [label=\"constant expression\"]\n",
               (unsigned long) node->ce);
      node->ce->dot_create (node->ce, f);
      break;

    case LABEL_DEFAULT:
      do_term (node, f, "default", 0);
      do_term (node, f, ":", 1);
      fprintf (f, "\%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->s);
      fprintf (f, "\%lu [label=\"statement\"]\n", (unsigned long) node->s);
      node->s->dot_create (node->s, f);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct labeled_statement *node, FILE * f, const char *token,
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
