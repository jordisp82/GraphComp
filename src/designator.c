#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "designator.h"
#include "constant_expression.h"
#include "designator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct designator *node, FILE * f,
                     const char *token, int n_token);

struct designator *
designator_1 (void *ptr)
{
  assert (ptr != NULL);

  struct designator *buff = calloc (1, sizeof (struct designator));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR;
  buff->d_kind = DESIGNATOR_ARRAY;
  buff->ex = ptr;
  buff->ex->parent_kind = NODE_DESIGNATOR;
  buff->ex->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct designator *
designator_2 (const char *str)
{
  assert (str != NULL);

  struct designator *buff = calloc (1, sizeof (struct designator));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR;
  buff->d_kind = DESIGNATOR_FIELD;
  buff->str = strdup (str);
  assert (buff->str != NULL);

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct designator *node = Node;
  assert (node->kind == NODE_DESIGNATOR);
  FILE *f = F;

  switch (node->d_kind)
    {
    case DESIGNATOR_ARRAY:
      do_term (node, f, "[", 0);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ex);
      fprintf (f, "\t%lu [label=\"constant expression\"]\n",
               (unsigned long) node->ex);
      node->ex->dot_create (node->ex, f);
      do_term (node, f, "]", 1);
      break;

    case DESIGNATOR_FIELD:
      do_term (node, f, ".", 0);
      do_term (node, f, node->str, 1);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct designator *node, FILE * f, const char *token, int n_token)
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
