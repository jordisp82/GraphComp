#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "function_definition.h"
#include "declaration_specifiers.h"
#include "declarator.h"
#include "declaration_list.h"
#include "compound_statement.h"
#include "direct_declarator.h"
#include "external_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct function_definition *
function_definition_1 (void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);
  assert (ptr4 != NULL);

  struct function_definition *buff =
    calloc (1, sizeof (struct function_definition));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_DEFINITION;
  buff->fd_kind = FD_K_AND_R;
  buff->ds = ptr1;
  buff->dr = ptr2;
  buff->dl = ptr3;
  buff->cs = ptr4;
  buff->ds->parent_kind = buff->dr->parent_kind = buff->dl->parent_kind =
    buff->cs->parent_kind = NODE_FUNCTION_DEFINITION;
  buff->ds->parent = buff->dr->parent = buff->dl->parent = buff->cs->parent =
    buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct function_definition *
function_definition_2 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);
  struct function_definition *buff =
    calloc (1, sizeof (struct function_definition));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_DEFINITION;
  buff->fd_kind = FD_STANDARD_C;
  buff->ds = ptr1;
  buff->dr = ptr2;
  buff->cs = ptr3;
  buff->ds->parent_kind = buff->dr->parent_kind = buff->cs->parent_kind =
    NODE_FUNCTION_DEFINITION;
  buff->ds->parent = buff->dr->parent = buff->cs->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct function_definition *node = Node;
  assert (node->kind == NODE_FUNCTION_DEFINITION);
  FILE *f = F;

  assert (node->ds != NULL);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->ds);
  fprintf (f, "\t%lu [label=\"declaration specifiers\"]\n",
           (unsigned long) node->ds);
  node->ds->dot_create (node->ds, f);

  assert (node->dr != NULL);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->dr);
  fprintf (f, "\t%lu [label=\"declarator\"]\n", (unsigned long) node->dr);
  node->dr->dot_create (node->dr, f);

  if (node->dl != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->dl);
      fprintf (f, "\t%lu [label=\"declaration list\"]\n",
               (unsigned long) node->dl);
      node->dl->dot_create (node->dl, f);
    }

  assert (node->cs != NULL);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->cs);
  fprintf (f, "\t%lu [label=\"compount statement\"]\n",
           (unsigned long) node->cs);
  node->cs->dot_create (node->cs, f);
}
