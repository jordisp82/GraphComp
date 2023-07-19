#include <assert.h>
#include <stdlib.h>

#include "external_declaration.h"
#include "function_definition.h"
#include "declaration.h"
#include "translation_unit.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ed_create_symtable (struct external_declaration *buff);
static void ed_create_symbol (struct external_declaration *buff);

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
  buff->create_symtable = ed_create_symtable;
  buff->create_symbol = ed_create_symbol;

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
  buff->create_symtable = ed_create_symtable;
  buff->create_symbol = ed_create_symbol;

  return buff;
}

static void
ed_create_symtable (struct external_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXTERNAL_DECLARATION);

  buff->sym_table = ((struct translation_unit *) (buff->parent))->sym_table;
  switch (buff->child_kind)
    {
    case NODE_DECLARATION:
      buff->d->create_symtable (buff->d);
      break;

    case NODE_FUNCTION_DEFINITION:
      buff->fd->create_symtable (buff->fd);
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
ed_create_symbol (struct external_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXTERNAL_DECLARATION);
  assert (buff->sym_table != NULL);

  switch (buff->child_kind)
    {
    case NODE_DECLARATION:
      buff->d->create_symbol (buff->d);
      break;

    case NODE_FUNCTION_DEFINITION:
      buff->fd->create_symbol (buff->fd);
      break;

    default:
      ;                         /* BUG! */
    }
}
