#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "init_declarator.h"
#include "declarator.h"
#include "initializer.h"
#include "declaration.h"
#include "init_declarator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct init_declarator *
init_declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct init_declarator *buff = calloc (1, sizeof (struct init_declarator));
  assert (buff);
  buff->kind = NODE_INIT_DECLARATOR;
  buff->dclr = ptr1;
  buff->itz = ptr2;
  buff->dclr->parent_kind = buff->itz->parent_kind = NODE_INIT_DECLARATOR;
  buff->dclr->parent = buff->itz->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct init_declarator *
init_declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct init_declarator *buff = calloc (1, sizeof (struct init_declarator));
  assert (buff);
  buff->kind = NODE_INIT_DECLARATOR;
  buff->dclr = ptr;
  buff->dclr->parent_kind = NODE_INIT_DECLARATOR;
  buff->dclr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct init_declarator *node = Node;
  assert (node->kind == NODE_INIT_DECLARATOR);
  FILE *f = F;

  if (node->dclr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->dclr);
      fprintf (f, "\t%lu [label=\"declarator\"]\n",
               (unsigned long) node->dclr);
      node->dclr->dot_create (node->dclr, f);
    }
  if (node->itz != NULL)
    {
      fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node,
               (unsigned long) node);
      fprintf (f, "\t%lu0 [lablel=\"=\",shape=box,fontname=Courier]\n",
               (unsigned long) node);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->itz);
      fprintf (f, "\t%lu [label=\"initializer\"]\n",
               (unsigned long) node->itz);
      node->itz->dot_create (node->itz, f);
    }
}
