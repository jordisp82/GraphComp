#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pointer.h"
#include "type_qualifier_list.h"
#include "declarator.h"
#include "abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct pointer *
pointer_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_TQ_PTR;
  buff->tql = ptr1;
  buff->ptr = ptr2;
  buff->tql->parent_kind = buff->ptr->parent_kind = NODE_POINTER;
  buff->tql->parent = buff->ptr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct pointer *
pointer_2 (void *ptr)
{
  assert (ptr != NULL);

  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_TQ;
  buff->tql = ptr;
  buff->tql->parent_kind = NODE_POINTER;
  buff->tql->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct pointer *
pointer_3 (void *ptr)
{
  assert (ptr != NULL);

  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_PTR;
  buff->ptr = ptr;
  buff->ptr->parent_kind = NODE_POINTER;
  buff->ptr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct pointer *
pointer_4 (void)
{
  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_EMPTY;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct pointer *node = Node;
  assert (node->kind == NODE_POINTER);
  FILE *f = F;

  fprintf (f, "\t%lu -> %lu0;\n", (unsigned long) node, (unsigned long) node);
  fprintf (f, "\t%lu0 [label=\"*\",shape=box,fontname=Courier]\n",
           (unsigned long) node);

  switch (node->ptr_kind)
    {
    case PTR_TQ:
      assert (node->tql);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->tql);
      fprintf (f, "\t%lu [label=\"type qualifier list\"]\n",
               (unsigned long) node->tql);
      node->tql->dot_create (node->tql, f);
      break;

    case PTR_TQ_PTR:
      assert (node->tql);
      assert (node->ptr);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->tql);
      fprintf (f, "\t%lu [label=\"type qualifier list\"]\n",
               (unsigned long) node->tql);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ptr);
      fprintf (f, "\t%lu [label=\"pointer\"]\n", (unsigned long) node->ptr);
      node->tql->dot_create (node->tql, f);
      node->ptr->dot_create (node->ptr, f);
      break;

    case PTR_PTR:
      assert (node->ptr);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ptr);
      fprintf (f, "\t%lu [label=\"pointer\"]\n", (unsigned long) node->ptr);
      node->ptr->dot_create (node->ptr, f);
      break;

    case PTR_EMPTY:
      break;

    default:;                  /* BUG! */
    }
}
