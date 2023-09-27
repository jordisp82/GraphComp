#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct_or_union.h"
#include "struct_or_union_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct struct_or_union *node, FILE * f,
                     const char *token, int n_token);

struct struct_or_union *
struct_or_union_1 (void)
{
  struct struct_or_union *buff = calloc (1, sizeof (struct struct_or_union));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION;
  buff->value = SU_STRUCT;

  buff->dot_create = local_dot_create;

  return buff;
}

struct struct_or_union *
struct_or_union_2 (void)
{
  struct struct_or_union *buff = calloc (1, sizeof (struct struct_or_union));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION;
  buff->value = SU_UNION;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct struct_or_union *node = Node;
  assert (node->kind == NODE_STRUCT_OR_UNION);
  FILE *f = F;

  switch (node->value)
    {
    case SU_STRUCT:
      do_term (node, f, "struct", 0);
      break;

    case SU_UNION:
      do_term (node, f, "union", 0);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct struct_or_union *node, FILE * f, const char *token,
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
