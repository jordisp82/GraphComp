#include <assert.h>
#include <stdlib.h>

#include "exclusive_or_expression.h"
#include "and_expression.h"
#include "inclusive_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void xor_create_symtable (struct exclusive_or_expression *buff);
static void xor_create_symbol (struct exclusive_or_expression *buff);

struct exclusive_or_expression *
exclusive_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct exclusive_or_expression *buff =
    calloc (1, sizeof (struct exclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->and_e = ptr;
  buff->and_e->parent_kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->and_e->parent = buff;
  buff->create_symtable = xor_create_symtable;
  buff->create_symbol = xor_create_symbol;

  return buff;
}

struct exclusive_or_expression *
exclusive_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct exclusive_or_expression *buff =
    calloc (1, sizeof (struct exclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->xor_e = ptr1;
  buff->and_e = ptr2;
  buff->xor_e->parent_kind = buff->and_e->parent_kind =
    NODE_EXCLUSIVE_OR_EXPRESSION;
  buff->xor_e->parent = buff->and_e->parent = buff;
  buff->create_symtable = xor_create_symtable;
  buff->create_symbol = xor_create_symbol;

  return buff;
}

static void
xor_create_symtable (struct exclusive_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXCLUSIVE_OR_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_EXCLUSIVE_OR_EXPRESSION:
      buff->sym_table =
        ((struct exclusive_or_expression *) (buff->parent))->sym_table;
      break;

    case NODE_INCLUSIVE_OR_EXPRESSION:
      buff->sym_table =
        ((struct inclusive_or_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->and_e != NULL)
    buff->and_e->create_symtable (buff->and_e);
  if (buff->xor_e != NULL)
    buff->xor_e->create_symtable (buff->xor_e);
}

static void
xor_create_symbol (struct exclusive_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXCLUSIVE_OR_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->and_e != NULL)
    buff->and_e->create_symbol (buff->and_e);
  if (buff->xor_e != NULL)
    buff->xor_e->create_symbol (buff->xor_e);
}
