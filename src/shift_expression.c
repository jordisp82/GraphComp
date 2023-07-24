#include <assert.h>
#include <stdlib.h>

#include "shift_expression.h"
#include "additive_expression.h"
#include "relational_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sh_create_symtable (struct shift_expression *buff);
static void sh_create_symbol (struct shift_expression *buff);

struct shift_expression *
shift_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct shift_expression *buff =
    calloc (1, sizeof (struct shift_expression));
  assert (buff != NULL);
  buff->kind = NODE_SHIFT_EXPRESSION;
  buff->sh_kind = SHIFT_NONE;
  buff->add_ex = ptr;
  buff->add_ex->parent_kind = NODE_SHIFT_EXPRESSION;
  buff->add_ex->parent = buff;
  buff->create_symtable = sh_create_symtable;
  buff->create_symbol = sh_create_symbol;

  return buff;
}

struct shift_expression *
shift_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct shift_expression *buff =
    calloc (1, sizeof (struct shift_expression));
  assert (buff != NULL);
  buff->kind = NODE_SHIFT_EXPRESSION;
  buff->sh_kind = SHIFT_LEFT;
  buff->sh_ex = ptr1;
  buff->add_ex = ptr2;
  buff->sh_ex->parent_kind = buff->add_ex->parent_kind =
    NODE_SHIFT_EXPRESSION;
  buff->sh_ex->parent = buff->add_ex->parent = buff;
  buff->create_symtable = sh_create_symtable;
  buff->create_symbol = sh_create_symbol;

  return buff;
}

struct shift_expression *
shift_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct shift_expression *buff =
    calloc (1, sizeof (struct shift_expression));
  assert (buff != NULL);
  buff->kind = NODE_SHIFT_EXPRESSION;
  buff->sh_kind = SHIFT_RIGHT;
  buff->sh_ex = ptr1;
  buff->add_ex = ptr2;
  buff->sh_ex->parent_kind = buff->add_ex->parent_kind =
    NODE_SHIFT_EXPRESSION;
  buff->sh_ex->parent = buff->add_ex->parent = buff;
  buff->create_symtable = sh_create_symtable;
  buff->create_symbol = sh_create_symbol;

  return buff;
}

static void
sh_create_symtable (struct shift_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_SHIFT_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_SHIFT_EXPRESSION:
      buff->sym_table =
        ((struct shift_expression *) (buff->parent))->sym_table;
      break;

    case NODE_RELATIONAL_EXPRESSION:
      buff->sym_table =
        ((struct relational_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->add_ex != NULL)
    buff->add_ex->create_symtable (buff->add_ex);
  if (buff->sh_ex != NULL)
    buff->sh_ex->create_symtable (buff->sh_ex);
}

static void
sh_create_symbol (struct shift_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_SHIFT_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->add_ex != NULL)
    buff->add_ex->create_symbol (buff->add_ex);
  if (buff->sh_ex != NULL)
    buff->sh_ex->create_symbol (buff->sh_ex);
}
