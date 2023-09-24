#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "initializer.h"
#include "initializer_list.h"
#include "assignment_expression.h"
#include "init_declarator.h"
#include "initializer_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct initializer *
initializer_1 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_LIST;
  buff->il = ptr;
  buff->il->parent_kind = NODE_INITIALIZER;
  buff->il->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct initializer *
initializer_2 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_LIST;
  buff->il = ptr;
  buff->il->parent_kind = NODE_INITIALIZER;
  buff->il->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct initializer *
initializer_3 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_ASS_EXPR;
  buff->ae = ptr;
  buff->ae->parent_kind = NODE_INITIALIZER;
  buff->ae->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct initializer *node = Node;
  assert (node->kind == NODE_INITIALIZER);
  FILE *f = F;

  switch (node->child_kind)
    {
    case IN_LIST:
      assert (node->il != NULL);
      /*
       * NOTE: if there is a trailing comma
       * before the closing curly brace,
       * we ignore it.
       */
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [label=\"{\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->il);
      fprintf (f, "\t%lu [label=\"initializer list\"]\n",
               (unsigned long) node->il);
      fprintf (f, "\t%lu -> %lu1;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu1 [label=\"}\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      node->il->dot_create (node->il, f);
      break;

    case IN_ASS_EXPR:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ae);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) node->ae);
      node->ae->dot_create (node->ae, f);
      break;

    default:;                  /* BUG! */
    }
}
