#include <assert.h>
#include <stdlib.h>

#include "and_expression.h"
#include "equality_expression.h"
#include "exclusive_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ae_create_symtable (struct and_expression *buff);
static void ae_create_symbol (struct and_expression *buff);

struct and_expression *
and_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct and_expression *buff = calloc (1, sizeof (struct and_expression));
  assert (buff != NULL);
  buff->kind = NODE_AND_EXPRESSION;
  buff->eq = ptr;
  buff->eq->parent_kind = NODE_AND_EXPRESSION;
  buff->eq->parent = buff;
  buff->create_symtable = ae_create_symtable;
  buff->create_symbol = ae_create_symbol;

  return buff;
}

struct and_expression *
and_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct and_expression *buff = calloc (1, sizeof (struct and_expression));
  assert (buff != NULL);
  buff->kind = NODE_AND_EXPRESSION;
  buff->and_e = ptr1;
  buff->eq = ptr2;
  buff->and_e->parent_kind = buff->eq->parent_kind = NODE_AND_EXPRESSION;
  buff->and_e->parent = buff->eq->parent = buff;
  buff->create_symtable = ae_create_symtable;
  buff->create_symbol = ae_create_symbol;

  return buff;
}

static void
ae_create_symtable (struct and_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_AND_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_AND_EXPRESSION:
      buff->sym_table = ((struct and_expression *) (buff->parent))->sym_table;
      break;

    case NODE_EXCLUSIVE_OR_EXPRESSION:
      buff->sym_table =
        ((struct exclusive_or_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->eq != NULL)
    buff->eq->create_symtable (buff->eq);
  if (buff->and_e != NULL)
    buff->and_e->create_symtable (buff->and_e);
}

static void
ae_create_symbol (struct and_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_AND_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->eq != NULL)
    buff->eq->create_symbol (buff->eq);
  if (buff->and_e != NULL)
    buff->and_e->create_symbol (buff->and_e);
}
