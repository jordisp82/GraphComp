#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct_declarator_list.h"
#include "struct_declarator.h"
#include "struct_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct struct_declarator_list *node, FILE * f,
                     const char *token, int n_token);

struct struct_declarator_list *
struct_declarator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declarator_list *buff =
    calloc (1, sizeof (struct struct_declarator_list));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATOR_LIST;
  buff->first = calloc (1, sizeof (struct sdl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->sd = ptr;
  buff->first->sd->parent_kind = NODE_STRUCT_DECLARATOR_LIST;
  buff->first->sd->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct struct_declarator_list *
struct_declarator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declarator_list *buff = ptr1;
  struct struct_declarator *d = ptr2;

  buff->last->next = calloc (1, sizeof (struct sdl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->sd = d;
  d->parent_kind = NODE_STRUCT_DECLARATOR_LIST;
  d->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct struct_declarator_list *node = Node;
  assert (node->kind == NODE_STRUCT_DECLARATOR_LIST);
  FILE *f = F;

  int i = 0;

  for (struct sdl_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) ptr->sd);
      fprintf (f, "\t%lu [label=\"struct declarator\"]\n",
               (unsigned long) ptr->sd);
      ptr->sd->dot_create (ptr->sd, f);
      if (ptr->next != NULL)
        do_term (node, f, ",", i++);
    }
}

static void
do_term (struct struct_declarator_list *node, FILE * f, const char *token,
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
