#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "designation.h"
#include "designator_list.h"
#include "initializer_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct designation *node, FILE * f,
                     const char *token, int n_token);

struct designation *
designation_1 (void *ptr)
{
  assert (ptr != NULL);

  struct designation *buff = calloc (1, sizeof (struct designation));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATION;
  buff->dl = ptr;
  buff->dl->parent_kind = NODE_DESIGNATION;
  buff->dl->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct designation *node = Node;
  assert (node->kind == NODE_DESIGNATION);
  FILE *f = F;

  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->dl);
  fprintf (f, "\t%lu [label=\"designator list\"]\n",
           (unsigned long) node->dl);
  node->dl->dot_create (node->dl, f);
  do_term (node, f, "=", 0);
}

static void
do_term (struct designation *node, FILE * f, const char *token, int n_token)
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
