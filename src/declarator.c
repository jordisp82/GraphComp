#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "declarator.h"
#include "pointer.h"
#include "direct_declarator.h"
#include "init_declarator.h"
#include "struct_declarator.h"
#include "direct_declarator.h"
#include "parameter_declaration.h"
#include "function_definition.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct declarator *
declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declarator *buff = calloc (1, sizeof (struct declarator));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATOR;
  buff->dclr_kind = DCLR_WITH_POINTER;
  buff->ptr = ptr1;
  buff->ddclr = ptr2;
  buff->ptr->parent_kind = buff->ddclr->parent_kind = NODE_DECLARATOR;
  buff->ptr->parent = buff->ddclr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct declarator *
declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct declarator *buff = calloc (1, sizeof (struct declarator));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATOR;
  buff->dclr_kind = DCLR_NO_POINTER;
  buff->ddclr = ptr;
  buff->ddclr->parent_kind = NODE_DECLARATOR;
  buff->ddclr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct declarator *node = Node;
  assert (node->kind == NODE_DECLARATOR);
  FILE *f = F;

  if (node->ptr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ptr);
      fprintf (f, "\t%lu [label=\"pointer\"]\n", (unsigned long) node->ptr);
      node->ptr->dot_create (node->ptr, f);
    }
  if (node->ddclr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ddclr);
      fprintf (f, "\t%lu [label=\"direct declarator\"]\n",
               (unsigned long) node->ddclr);
      node->ddclr->dot_create (node->ddclr, f);
    }
}
