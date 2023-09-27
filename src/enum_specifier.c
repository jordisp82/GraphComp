#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enum_specifier.h"
#include "enumerator_list.h"
#include "type_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct enum_specifier *node, FILE * f,
                     const char *token, int n_token);

struct enum_specifier *
enum_specifier_1 (void *ptr)
{
  assert (ptr != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->el = ptr;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct enum_specifier *
enum_specifier_2 (void *ptr)
{
  assert (ptr != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->el = ptr;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct enum_specifier *
enum_specifier_3 (const char *str, void *ptr2)
{
  assert (str != NULL);
  assert (ptr2 != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->tag = strdup (str);
  buff->el = ptr2;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct enum_specifier *
enum_specifier_4 (const char *str, void *ptr2)
{
  assert (str != NULL);
  assert (ptr2 != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->tag = strdup (str);
  buff->el = ptr2;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct enum_specifier *
enum_specifier_5 (const char *str)
{
  assert (str != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->tag = strdup (str);

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct enum_specifier *node = Node;
  assert (node->kind == NODE_ENUM_SPECIFIER);
  FILE *f = F;

  do_term (node, f, "enum", 0);
  if (node->tag != NULL)
    do_term (node, f, node->tag, 1);
  if (node->el != NULL)
    {
      do_term (node, f, "{", 2);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->el);
      fprintf (f, "\t%lu [label=\"enumerator list\"]\n",
               (unsigned long) node->el);
      node->el->dot_create (node->el, f);
      /* NOTE fuck off any trailing comma */
      do_term (node, f, "}", 3);
    }
}

static void
do_term (struct enum_specifier *node, FILE * f, const char *token,
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
