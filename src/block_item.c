#include <assert.h>
#include <stdlib.h>

#include "block_item.h"
#include "declaration.h"
#include "statement.h"
#include "block_item_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void bi_create_symtable (struct block_item *buff);

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
  buff->create_symtable = bi_create_symtable;

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
  buff->create_symtable = bi_create_symtable;

  return buff;
}

static void
bi_create_symtable (struct block_item *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_BLOCK_ITEM);

  buff->sym_table = ((struct block_item_list *) (buff->parent))->sym_table;
  switch (buff->child_kind)
    {
    case NODE_DECLARATION:
      buff->d->create_symtable (buff->d);
      break;

    case NODE_STATEMENT:
      buff->s->create_symtable (buff->s);
      break;

    default:
      ;                         /* BUG! */
    }
}

#if 0
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
set_symbol_for_block_item (struct block_item *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_BLOCK_ITEM);

  switch (buff->child_kind)
    {
    case NODE_DECLARATION:
      set_symbol_for_declaration (buff->d);
      break;

    case NODE_STATEMENT:
      set_symbol_for_statement (buff->s);
      break;

    default:
      ;                         /* BUG! */
    }
}
#endif
