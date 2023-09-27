#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct_declaration_list.h"
#include "struct_declaration.h"
#include "struct_or_union_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct struct_declaration_list *
struct_declaration_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declaration_list *buff =
    calloc (1, sizeof (struct struct_declaration_list));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION_LIST;
  buff->first = calloc (1, sizeof (struct sdln_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->sd = ptr;
  buff->first->sd->parent_kind = NODE_STRUCT_DECLARATION_LIST;
  buff->first->sd->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct struct_declaration_list *
struct_declaration_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declaration_list *buff = ptr1;
  struct struct_declaration *sd = ptr2;

  buff->last->next = calloc (1, sizeof (struct sdln_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->sd = sd;
  sd->parent_kind = NODE_STRUCT_DECLARATION_LIST;
  sd->parent = sd;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct struct_declaration_list *node = Node;
  assert (node->kind == NODE_STRUCT_DECLARATION_LIST);
  FILE *f = F;

  for (struct sdln_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) ptr->sd);
      fprintf (f, "\t%lu [label=\"struct declaration\"]\n",
               (unsigned long) ptr->sd);
      ptr->sd->dot_create (ptr->sd, f);
    }
}
