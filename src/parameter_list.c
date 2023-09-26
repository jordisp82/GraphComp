#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "parameter_list.h"
#include "parameter_declaration.h"
#include "parameter_type_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct parameter_list *
parameter_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_list *buff = calloc (1, sizeof (struct parameter_list));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_LIST;
  buff->first = calloc (1, sizeof (struct pl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->pd = ptr;
  buff->first->pd->parent_kind = NODE_PARAMETER_LIST;
  buff->first->pd->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct parameter_list *
parameter_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct parameter_list *buff = ptr1;
  struct parameter_declaration *pd = ptr2;

  buff->last->next = calloc (1, sizeof (struct pl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->pd = pd;
  pd->parent_kind = NODE_PARAMETER_LIST;
  pd->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct parameter_list *node = Node;
  assert (node->kind == NODE_PARAMETER_LIST);
  FILE *f = F;

  for (struct pl_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) ptr->pd);
      fprintf (f, "\t%lu [label=\"parameter declaration\"]\n",
               (unsigned long) ptr->pd);
      ptr->pd->dot_create (ptr->pd, f);
    }
}
