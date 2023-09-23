#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "declaration.h"
#include "declaration_specifiers.h"
#include "init_declarator_list.h"
#include "static_assert_declaration.h"
#include "external_declaration.h"
#include "block_item.h"
#include "block_item_list.h"
#include "declaration_list.h"
#include "function_definition.h"
#include "ast.h"
#include "iteration_statement.h"
#include "declaration_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct declaration *
declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr;
  buff->ds->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct declaration *
declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr1;
  buff->idl = ptr2;
  buff->ds->parent_kind = buff->idl->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff->idl->parent = buff;

  buff->dot_create = local_dot_create;

  if (look_for_typedef (buff->ds) == 1)
    register_ids_as_typedef (buff->idl);

  return buff;
}

struct declaration *
declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->sad = ptr;
  buff->sad->parent_kind = NODE_DECLARATION;
  buff->sad->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct declaration *node = Node;
  assert (node->kind == NODE_DECLARATION);
  FILE *f = F;

  if (node->ds != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ds);
      fprintf (f, "\t%lu [label=\"declaration specifiers\"]\n",
               (unsigned long) node->ds);
      node->ds->dot_create (node->ds, f);
    }
  if (node->idl != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->idl);
      fprintf (f, "\t%lu [label=\"init declarator list\"]\n",
               (unsigned long) node->idl);
      node->idl->dot_create (node->idl, f);
    }
  if (node->sad != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sad);
      fprintf (f, "\t%lu [label=\"static assert declaration\"]\n",
               (unsigned long) node->sad);
      /* NOTE fuck off static assert declarations */
    }
}
