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

void
set_block_item_scope (struct block_item *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_BLOCK_ITEM);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_BLOCK_ITEM_LIST:
        set_block_item_list_scope (buff->parent);
        buff->scope = ((struct block_item_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct block_item_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
fill_in_symtable_block_item (struct block_item *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_BLOCK_ITEM);

  switch (buff->child_kind)
    {
    case NODE_DECLARATION:
      fill_in_symtable_declaration (buff->d);
      break;

    case NODE_STATEMENT:
      fill_in_symtable_statement (buff->s);
      break;

    default:
      ;                         /* BUG! */
    }
}
