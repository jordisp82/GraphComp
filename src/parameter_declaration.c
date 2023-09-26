#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "parameter_declaration.h"
#include "declaration_specifiers.h"
#include "declarator.h"
#include "abstract_declarator.h"
#include "parameter_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct parameter_declaration *
parameter_declaration_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct parameter_declaration *buff =
    calloc (1, sizeof (struct parameter_declaration));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_DECLARATION;
  buff->pd_kind = PD_DS_DECLR;
  buff->ds = ptr1;
  buff->dr = ptr2;
  buff->ds->parent_kind = buff->dr->parent_kind = NODE_PARAMETER_DECLARATION;
  buff->ds->parent = buff->dr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct parameter_declaration *
parameter_declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct parameter_declaration *buff =
    calloc (1, sizeof (struct parameter_declaration));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_DECLARATION;
  buff->pd_kind = PD_DS_ABS_DECLR;
  buff->ds = ptr1;
  buff->adr = ptr2;
  buff->ds->parent_kind = buff->adr->parent_kind = NODE_PARAMETER_DECLARATION;
  buff->ds->parent = buff->adr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct parameter_declaration *
parameter_declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_declaration *buff =
    calloc (1, sizeof (struct parameter_declaration));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_DECLARATION;
  buff->pd_kind = PD_DS;
  buff->ds = ptr;
  buff->ds->parent_kind = NODE_PARAMETER_DECLARATION;
  buff->ds->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct parameter_declaration *node = Node;
  assert (node->kind == NODE_PARAMETER_DECLARATION);
  FILE *f = F;

  assert (node->ds != NULL);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->ds);
  fprintf (f, "\t%lu [label=\"declaration specifiers\"]\n",
           (unsigned long) node->ds);
  node->ds->dot_create (node->ds, f);

  if (node->dr != NULL && node->adr == NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->dr);
      fprintf (f, "\t%lu [label=\"declarator\"]\n", (unsigned long) node->dr);
      node->dr->dot_create (node->dr, f);
    }
  else if (node->adr != NULL && node->dr == NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->adr);
      fprintf (f, "\t%lu [label=\"abstract declarator\"]\n",
               (unsigned long) node->adr);
      node->adr->dot_create (node->adr, f);
    }
  else
    {                           /* BUG! */
    }
}
