#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "declaration_list.h"
#include "declaration.h"
#include "function_definition.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct declaration_list *
declaration_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_list *buff =
    calloc (1, sizeof (struct declaration_list));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_LIST;
  buff->first = calloc (1, sizeof (struct dl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->dl = ptr;
  buff->first->dl->parent_kind = NODE_DECLARATION_LIST;
  buff->first->dl->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct declaration_list *
declaration_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declaration_list *buff = ptr1;
  struct declaration *dl = ptr2;

  buff->last->next = calloc (1, sizeof (struct dl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->dl = dl;
  dl->parent_kind = NODE_DECLARATION_LIST;
  dl->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct declaration_list *node = Node;
  assert (node->kind == NODE_FUNCTION_DEFINITION);
  FILE *f = F;

  assert (Node != NULL);
  assert (F != NULL);

  for (struct dl_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) ptr->dl);
      fprintf (f, "\t%lu [label=\"declaration\"]\n", (unsigned long) ptr->dl);
      ptr->dl->dot_create (ptr->dl, f);
    }
}
