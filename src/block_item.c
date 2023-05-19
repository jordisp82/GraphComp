#include <assert.h>
#include <stdlib.h>

#include "block_item.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct block_item *
block_item_1 (void *ptr)
{
  assert (ptr != NULL);

  struct block_item *buff = calloc (1, sizeof (struct block_item));
  assert (buff != NULL);
  buff->kind = NODE_BLOCK_ITEM;
  buff->child_kind = NODE_DECLARATION;
  buff->d = ptr;
#if 0
  buff->d->parent_kind = NODE_BLOCK_ITEM;
  buff->d->parent = buff;
#endif

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
#if 0
  buff->s->parent_kind = NODE_BLOCK_ITEM;
  buff->s->parent = buff;
#endif

  return buff;
}
