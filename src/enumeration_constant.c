#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enumeration_constant.h"
#include "enumerator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct enumeration_constant *
enumeration_constant_1 (const char *str)
{
  assert (str != NULL);

  struct enumeration_constant *buff =
    calloc (1, sizeof (struct enumeration_constant));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATION_CONSTANT;
  buff->str = strdup (str);
  assert (buff->str != NULL);

  add_enumeration_constant (str);
  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct enumeration_constant *node = Node;
  assert (node->kind == NODE_ENUMERATION_CONSTANT);
  FILE *f = F;

  fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node, (unsigned long) node);
  fprintf (f, "\t%lu0 [label=\"%s\",shape=box,fontname=Courier]\n",
           (unsigned long) node, node->str);
}
