#include <assert.h>
#include <stdlib.h>

#include "init_declarator.h"
#include "declarator.h"
#include "initializer.h"
#include "declaration.h"
#include "init_declarator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct init_declarator *
init_declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct init_declarator *buff = calloc (1, sizeof (struct init_declarator));
  assert (buff);
  buff->kind = NODE_INIT_DECLARATOR;
  buff->dclr = ptr1;
  buff->itz = ptr2;
  buff->dclr->parent_kind = buff->itz->parent_kind = NODE_INIT_DECLARATOR;
  buff->dclr->parent = buff->itz->parent = buff;

  return buff;
}

struct init_declarator *
init_declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct init_declarator *buff = calloc (1, sizeof (struct init_declarator));
  assert (buff);
  buff->kind = NODE_INIT_DECLARATOR;
  buff->dclr = ptr;
  buff->dclr->parent_kind = NODE_INIT_DECLARATOR;
  buff->dclr->parent = buff;

  return buff;
}

symbol_t *
create_symbol_from_init_declarator (struct init_declarator *buff)
{
  assert (buff != NULL);

  return create_symbol_for_declarator (buff->dclr);
}

void
set_init_declarator_scope (struct init_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INIT_DECLARATOR);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_DECLARATION:
        set_declaration_scope (buff->parent);
        buff->scope = ((struct declaration *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct declaration *) (buff->parent))->scope_kind;
        break;

      case NODE_INIT_DECLARATOR_LIST:
        set_init_declarator_scope (buff->parent);
        buff->scope = ((struct init_declarator_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct init_declarator_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_init_declarator (struct init_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INIT_DECLARATOR);

  if (buff->itz != NULL)
    set_symbol_for_initializer (buff->itz);
}
