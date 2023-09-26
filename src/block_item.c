#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "block_item.h"
#include "declaration.h"
#include "statement.h"
#include "block_item_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct block_item *
block_item_1 (void *ptr)
{
  assert (ptr != NULL);

  struct block_item *buff = calloc (1, sizeof (struct block_item));
  assert (buff != NULL);
  buff->kind = NODE_BLOCK_ITEM;
  buff->child_kind = NODE_DECLARATION;
  buff->d = ptr;
  buff->d->parent_kind = NODE_BLOCK_ITEM;
  buff->d->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct block_item *
block_item_2 (void *ptr)
{
  assert (ptr != NULL);

  struct block_item *buff = calloc (1, sizeof (struct block_item));
  assert (buff != NULL);
  buff->kind = NODE_BLOCK_ITEM;
  buff->child_kind = NODE_STATEMENT;
  buff->s = ptr;
  buff->s->parent_kind = NODE_BLOCK_ITEM;
  buff->s->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct block_item *node = Node;
  assert (node->kind == NODE_BLOCK_ITEM);
  FILE *f = F;

  switch (node->child_kind)
    {
    case NODE_DECLARATION:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->d);
      fprintf (f, "\t%lu [label=\"declaration\"]\n", (unsigned long) node->d);
      node->d->dot_create (node->d, f);
      break;

    case NODE_STATEMENT:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->s);
      fprintf (f, "\t%lu [label=\"statement\"]\n", (unsigned long) node->s);
      node->s->dot_create (node->s, f);
      break;

    default:;                  /* BUG! */
    }
}
