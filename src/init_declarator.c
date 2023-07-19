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

static void id_create_symtable (struct init_declarator *buff);
static void id_create_symbol (struct init_declarator *buff);

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
  buff->create_symtable = id_create_symtable;
  buff->create_symbol = id_create_symbol;

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
  buff->create_symtable = id_create_symtable;
  buff->create_symbol = id_create_symbol;

  return buff;
}

static void
id_create_symtable (struct init_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INIT_DECLARATOR);

  switch (buff->parent_kind)
    {
    case NODE_DECLARATION:
      buff->sym_table = ((struct declaration *) (buff->parent))->sym_table;
      break;

    case NODE_INIT_DECLARATOR_LIST:
      buff->sym_table =
        ((struct init_declarator_list *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->dclr != NULL)
    buff->dclr->create_symtable (buff->dclr);
  if (buff->itz != NULL)
    buff->itz->create_symtable (buff->itz);
}

static void
id_create_symbol (struct init_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INIT_DECLARATOR);
  assert (buff->sym_table != NULL);

  if (buff->dclr != NULL)
    buff->dclr->create_symbol (buff->dclr);
  if (buff->itz != NULL)
    buff->itz->create_symbol (buff->itz);
}
