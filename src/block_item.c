#include <assert.h>
#include <stdlib.h>

#include "block_item.h"
#include "declaration.h"
#include "statement.h"
#include "block_item_list.h"

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
  buff->d->parent_kind = NODE_BLOCK_ITEM;
  buff->d->parent = buff;

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

  return buff;
}
