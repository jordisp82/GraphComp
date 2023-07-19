#include <assert.h>
#include <stdlib.h>

#include "initializer.h"
#include "initializer_list.h"
#include "assignment_expression.h"
#include "init_declarator.h"
#include "initializer_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void iz_create_symtable (struct initializer *buff);
static void iz_create_symbol (struct initializer *buff);

struct initializer *
initializer_1 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_LIST;
  buff->il = ptr;
  buff->il->parent_kind = NODE_INITIALIZER;
  buff->il->parent = buff;
  buff->create_symtable = iz_create_symtable;
  buff->create_symbol = iz_create_symbol;

  return buff;
}

struct initializer *
initializer_2 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_LIST;
  buff->il = ptr;
  buff->il->parent_kind = NODE_INITIALIZER;
  buff->il->parent = buff;
  buff->create_symtable = iz_create_symtable;
  buff->create_symbol = iz_create_symbol;

  return buff;
}

struct initializer *
initializer_3 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_ASS_EXPR;
  buff->ae = ptr;
  buff->ae->parent_kind = NODE_INITIALIZER;
  buff->ae->parent = buff;
  buff->create_symtable = iz_create_symtable;
  buff->create_symbol = iz_create_symbol;

  return buff;
}

static void
iz_create_symtable (struct initializer *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INITIALIZER);

  switch (buff->parent_kind)
    {
    case NODE_INIT_DECLARATOR:
      buff->sym_table =
        ((struct init_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_INITIALIZER_LIST:
      buff->sym_table =
        ((struct initializer_list *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  switch (buff->child_kind)
    {
    case IN_LIST:
      buff->il->create_symtable (buff->il);
      break;

    case IN_ASS_EXPR:
      buff->ae->create_symtable (buff->ae);
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
iz_create_symbol (struct initializer *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INITIALIZER);
  assert (buff->sym_table != NULL);

  switch (buff->child_kind)
    {
    case IN_LIST:
      buff->il->create_symbol (buff->il);
      break;

    case IN_ASS_EXPR:
      buff->ae->create_symbol (buff->ae);
      break;

    default:
      ;                         /* BUG! */
    }
}
