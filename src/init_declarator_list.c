#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "init_declarator_list.h"
#include "init_declarator.h"
#include "declaration.h"
#include "declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
/* NOTE start of experimental code */
static int local_sem_analysis (void *Node);
/* NOTE end of experimental code */

struct init_declarator_list *
init_declarator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct init_declarator_list *buff =
    calloc (1, sizeof (struct init_declarator_list));
  assert (buff != NULL);
  buff->kind = NODE_INIT_DECLARATOR_LIST;
  buff->first = calloc (1, sizeof (struct idl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->id = ptr;
  buff->first->id->parent_kind = NODE_INIT_DECLARATOR_LIST;
  buff->first->id->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct init_declarator_list *
init_declarator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct init_declarator_list *buff = ptr1;
  struct init_declarator *id = ptr2;

  buff->last->next = calloc (1, sizeof (struct idl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->id = id;
  id->parent_kind = NODE_INIT_DECLARATOR_LIST;
  id->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct init_declarator_list *node = Node;
  assert (node->kind == NODE_INIT_DECLARATOR_LIST);
  FILE *f = F;

  for (struct idl_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) ptr->id);
      fprintf (f, "\t%lu [label=\"init declarator\"]\n",
               (unsigned long) ptr->id);
      ptr->id->dot_create (ptr->id, f);
    }
}

/* NOTE start of experimental code */
static int
local_sem_analysis (void *Node)
{
  assert (Node != NULL);
  struct init_declarator_list *node = Node;
  assert (node->kind == NODE_INIT_DECLARATOR_LIST);

  for (struct idl_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    if (ptr->id->sem_analysis (ptr->id) < 0)
      return -1;

  return 0;
}

/* NOTE end of experimental code */
