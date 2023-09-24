#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "identifier_list.h"
#include "direct_declarator.h"
#include "identifier_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct identifier_list *
identifier_list_1 (const char *str)
{
  assert (str != NULL);

  struct identifier_list *buff = calloc (1, sizeof (struct identifier_list));
  assert (buff != NULL);
  buff->kind = NODE_IDENTIFIER_LIST;
  buff->first = calloc (1, sizeof (struct il_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->str = strdup (str);
  assert (buff->first->str != NULL);

  buff->dot_create = local_dot_create;

  return buff;
}

struct identifier_list *
identifier_list_2 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct identifier_list *buff = ptr1;
  buff->last->next = calloc (1, sizeof (struct il_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->str = strdup (str);
  assert (buff->last->str != NULL);

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct identifier_list *node = Node;
  assert (node->kind == NODE_IDENTIFIER_LIST);
  FILE *f = F;

  int i = 0;

  for (struct il_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu%d;\n", (unsigned long) node,
               (unsigned long) node, i);
      fprintf (f, "\t%lu%d [label=\"%s\",shape=box,fontname=Courier]\n",
               (unsigned long) node, i, ptr->str);
      i++;
      if (ptr->next != NULL)
        {
          fprintf (f, "\t%lu -> %lu%d;\n", (unsigned long) node,
                   (unsigned long) node, i);
          fprintf (f, "\t%lu%d [label=\",\",shape=box,fontname=Courier]\n",
                   (unsigned long) node, i);
          i++;
        }
    }
}
