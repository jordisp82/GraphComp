#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "type_qualifier_list.h"
#include "type_qualifier.h"
#include "direct_declarator.h"
#include "direct_abstract_declarator.h"
#include "pointer.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct type_qualifier_list *
type_qualifier_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct type_qualifier_list *buff =
    calloc (1, sizeof (struct type_qualifier_list));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER_LIST;
  buff->first = calloc (1, sizeof (struct tql_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->tq = ptr;
  buff->first->tq->parent_kind = NODE_TYPE_QUALIFIER_LIST;
  buff->first->tq->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_qualifier_list *
type_qualifier_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_qualifier_list *buff = ptr1;
  struct type_qualifier *tq = ptr2;

  buff->last->next = calloc (1, sizeof (struct tql_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->tq = tq;
  tq->parent_kind = NODE_TYPE_QUALIFIER_LIST;
  tq->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct type_qualifier_list *node = Node;
  assert (node->kind == NODE_TYPE_QUALIFIER_LIST);
  FILE *f = F;

  for (struct tql_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) ptr->tq);
      fprintf (f, "\t%lu [label=\"type qualifier\"]\n",
               (unsigned long) ptr->tq);
      ptr->tq->dot_create (ptr->tq, f);
    }
}
