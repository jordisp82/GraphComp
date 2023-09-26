#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "block_item_list.h"
#include "block_item.h"
#include "compound_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct block_item_list *
block_item_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct block_item_list *buff = calloc (1, sizeof (struct block_item_list));
  assert (buff != NULL);
  buff->kind = NODE_BLOCK_ITEM_LIST;
  buff->first = calloc (1, sizeof (struct bil_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->block_item = ptr;
  buff->first->block_item->parent_kind = NODE_BLOCK_ITEM_LIST;
  buff->first->block_item->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct block_item_list *
block_item_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct block_item_list *buff = ptr1;
  struct block_item *bi = ptr2;

  buff->last->next = calloc (1, sizeof (struct bil_node));
  assert (buff->last->next);
  buff->last = buff->last->next;
  buff->last->block_item = bi;
  bi->parent_kind = NODE_BLOCK_ITEM_LIST;
  bi->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct block_item_list *node = Node;
  assert (node->kind == NODE_BLOCK_ITEM_LIST);
  FILE *f = F;

  for (struct bil_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) ptr->block_item);
      fprintf (f, "\t%lu [label=\"block item\"]\n",
               (unsigned long) ptr->block_item);
      ptr->block_item->dot_create (ptr->block_item, f);
    }
}
