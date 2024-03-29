#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "external_declaration.h"
#include "function_definition.h"
#include "declaration.h"
#include "translation_unit.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
/* NOTE start of experimental code */
static int local_sem_analysis (void *Node);
/* NOTE end of experimental code */

struct external_declaration *
external_declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct external_declaration *buff =
    calloc (1, sizeof (struct external_declaration));
  assert (buff != NULL);
  buff->kind = NODE_EXTERNAL_DECLARATION;
  buff->child_kind = NODE_FUNCTION_DEFINITION;
  buff->fd = ptr;
  buff->fd->parent_kind = NODE_EXTERNAL_DECLARATION;
  buff->fd->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct external_declaration *
external_declaration_2 (void *ptr)
{
  assert (ptr != NULL);

  struct external_declaration *buff =
    calloc (1, sizeof (struct external_declaration));
  assert (buff != NULL);
  buff->kind = NODE_EXTERNAL_DECLARATION;
  buff->child_kind = NODE_DECLARATION;
  buff->d = ptr;
  buff->d->parent_kind = NODE_EXTERNAL_DECLARATION;
  buff->d->parent = buff;

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

  struct external_declaration *node = Node;
  assert (node->kind == NODE_EXTERNAL_DECLARATION);
  FILE *f = F;

  switch (node->child_kind)
    {
    case NODE_FUNCTION_DEFINITION:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->fd);
      fprintf (f, "\t%lu [label=\"function definition\"]\n",
               (unsigned long) node->fd);
      node->fd->dot_create (node->fd, f);
      break;

    case NODE_DECLARATION:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->d);
      fprintf (f, "\t%lu [label=\"declaration\"]\n", (unsigned long) node->d);
      node->d->dot_create (node->d, f);
      break;

    default:;                  /* BUG! */
    }
}

static int
local_sem_analysis (void *Node)
{
  assert (Node != NULL);
  struct external_declaration *node = Node;
  assert (node->kind == NODE_EXTERNAL_DECLARATION);

  switch (node->child_kind)
    {
    case NODE_FUNCTION_DEFINITION:
      /* TODO */
      return 0;

    case NODE_DECLARATION:
      return node->d->sem_analysis (node->d);

    default:;                  /* BUG! */
    }

  return -1;                    /* because of bug */
}
