#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "translation_unit.h"
#include "external_declaration.h"
#include "function_definition.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
/* NOTE start of experimental code */
static int local_sem_analysis (void *Node);
/* NOTE end of experimental code */

struct translation_unit *
translation_unit_1 (void *ptr)
{
  assert (ptr != NULL);

  struct translation_unit *buff =
    calloc (1, sizeof (struct translation_unit));
  assert (buff != NULL);
  buff->kind = NODE_TRANSLATION_UNIT;
  buff->first = calloc (1, sizeof (struct tu_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ed = ptr;
  buff->first->ed->parent = buff;
  buff->first->ed->parent_kind = NODE_TRANSLATION_UNIT;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct translation_unit *
translation_unit_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct translation_unit *buff = ptr1;
  struct external_declaration *ed = ptr2;

  buff->last->next = calloc (1, sizeof (struct tu_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ed = ed;
  ed->parent = buff;
  ed->parent_kind = NODE_TRANSLATION_UNIT;

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

  struct translation_unit *tu = Node;
  assert (tu->kind == NODE_TRANSLATION_UNIT);
  FILE *f = F;

  fprintf (f, "digraph tu {\n");
  for (struct tu_node * ptr = tu->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\ttu [label=\"translation unit\"]\n");
      fprintf (f, "\ttu -> %lu;\n", (unsigned long) ptr->ed);
      fprintf (f, "\t%lu [label=\"external declaration\"]\n",
               (unsigned long) ptr->ed);
      ptr->ed->dot_create (ptr->ed, f);
    }

  fprintf (f, "}\n");
}

static int
local_sem_analysis (void *Node)
{
  assert (Node != NULL);
  struct translation_unit *tu = Node;
  assert (tu->kind == NODE_TRANSLATION_UNIT);

  for (struct tu_node * ptr = tu->first; ptr != NULL; ptr = ptr->next)
    (void) ptr->ed->sem_analysis (ptr->ed);

  return 0;                     /* FIXME */
}
