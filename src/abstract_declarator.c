#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abstract_declarator.h"
#include "pointer.h"
#include "direct_abstract_declarator.h"
#include "parameter_declaration.h"
#include "type_name.h"
#include "direct_abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct abstract_declarator *
abstract_declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct abstract_declarator *buff =
    calloc (1, sizeof (struct abstract_declarator));
  assert (buff != NULL);
  buff->kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr = ptr1;
  buff->dad = ptr2;
  buff->ptr->parent_kind = buff->dad->parent_kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr->parent = buff->dad->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct abstract_declarator *
abstract_declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct abstract_declarator *buff =
    calloc (1, sizeof (struct abstract_declarator));
  assert (buff != NULL);
  buff->kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr = ptr;
  buff->ptr->parent_kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct abstract_declarator *
abstract_declarator_3 (void *ptr)
{
  assert (ptr != NULL);

  struct abstract_declarator *buff =
    calloc (1, sizeof (struct abstract_declarator));
  assert (buff != NULL);
  buff->kind = NODE_ABSTRACT_DECLARATOR;
  buff->dad = ptr;
  buff->dad->parent_kind = NODE_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct abstract_declarator *node = Node;
  assert (node->kind == NODE_ABSTRACT_DECLARATOR);
  FILE *f = F;

  if (node->ptr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ptr);
      fprintf (f, "\t%lu [label=\"pointer\"]\n", (unsigned long) node->ptr);
      node->ptr->dot_create (node->ptr, f);
    }
  if (node->dad != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->dad);
      fprintf (f, "\t%lu [label=\"direct abstract declarator\"]\n",
               (unsigned long) node->dad);
      /* TODO */
    }
}
