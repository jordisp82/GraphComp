#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_symbol.h"
#include "primary_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct string *
string_1 (const char *str)
{
  assert (str != NULL);

  struct string *buff = calloc (1, sizeof (struct string));
  assert (buff != NULL);
  buff->kind = NODE_STRING;
  buff->str_kind = STRING_STRING;
  buff->str = strdup (str);
  assert (buff->str != NULL);

  buff->dot_create = local_dot_create;

  return buff;
}

struct string *
string_2 (const char *str)
{
  assert (str != NULL);

  struct string *buff = calloc (1, sizeof (struct string));
  assert (buff != NULL);
  buff->kind = NODE_STRING;
  buff->str_kind = STRING_FUNC_NAME;
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

  struct string *node = Node;
  assert (node->kind == NODE_STRING);
  FILE *f = F;

  fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node, (unsigned long) node);
  fprintf (f, "\t%lu0 [label=\"%s\",shape=box,fontname=Courier]\n",
           (unsigned long) node, node->str);
}
