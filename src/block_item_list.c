#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "block_item_list.h"
#include "block_item.h"
#include "compound_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

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

  return buff;
}
