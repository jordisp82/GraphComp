#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "atomic_type_specifier.h"
#include "type_name.h"
#include "type_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct atomic_type_specifier *node, FILE * f,
                     const char *token, int n_token);

struct atomic_type_specifier *
atomic_type_specifier_1 (void *ptr)
{
  assert (ptr != NULL);

  struct atomic_type_specifier *buff =
    calloc (1, sizeof (struct atomic_type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ATOMIC_TYPE_SPECIFIER;
  buff->tn = ptr;
  buff->tn->parent_kind = NODE_ATOMIC_TYPE_SPECIFIER;
  buff->tn->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct atomic_type_specifier *node = Node;
  assert (node->kind == NODE_ATOMIC_TYPE_SPECIFIER);
  FILE *f = F;

  do_term (node, f, "_Atomic", 0);
  do_term (node, f, "(", 1);
  fprintf (f, "\t%lu -> %lu\n", (unsigned long) node,
           (unsigned long) node->tn);
  fprintf (f, "\t%lu [label=\"typename\"]\n", (unsigned long) node->tn);
  node->tn->dot_create (node->tn, f);
  do_term (node, f, ")", 2);
}

static void
do_term (struct atomic_type_specifier *node, FILE * f, const char *token,
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
