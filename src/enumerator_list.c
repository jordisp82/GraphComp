#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "enumerator_list.h"
#include "enumerator.h"
#include "enum_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct enumerator_list *node, FILE * f,
                     const char *token, int n_token);

struct enumerator_list *
enumerator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct enumerator_list *buff = calloc (1, sizeof (struct enumerator_list));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR_LIST;
  buff->first = calloc (1, sizeof (struct enl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->en = ptr;
  buff->first->en->parent_kind = NODE_ENUMERATOR_LIST;
  buff->first->en->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct enumerator_list *
enumerator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct enumerator_list *buff = ptr1;
  struct enumerator *en = ptr2;

  buff->last->next = calloc (1, sizeof (struct enl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->en = en;
  en->parent_kind = NODE_ENUMERATOR_LIST;
  en->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct enumerator_list *node = Node;
  assert (node->kind == NODE_ENUMERATOR_LIST);
  FILE *f = F;

  int n = 0;

  for (struct enl_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) ptr->en);
      fprintf (f, "\t%lu [label=\"enumerator\"]\n", (unsigned long) ptr->en);
      ptr->en->dot_create (ptr->en, f);
      if (ptr->next != NULL)
        do_term (node, f, ",", n++);
    }
}

static void
do_term (struct enumerator_list *node, FILE * f, const char *token,
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
