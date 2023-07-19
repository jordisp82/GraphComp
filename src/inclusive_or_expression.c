#include <assert.h>
#include <stdlib.h>

#include "inclusive_or_expression.h"
#include "exclusive_or_expression.h"
#include "logical_and_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void or_create_symtable (struct inclusive_or_expression *buff);
static void or_create_symbol (struct inclusive_or_expression *buff);

struct inclusive_or_expression *
inclusive_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct inclusive_or_expression *buff =
    calloc (1, sizeof (struct inclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->xor_e = ptr;
  buff->xor_e->parent_kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->xor_e->parent = buff;
  buff->create_symtable = or_create_symtable;
  buff->create_symbol = or_create_symbol;

  return buff;
}

struct inclusive_or_expression *
inclusive_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct inclusive_or_expression *buff =
    calloc (1, sizeof (struct inclusive_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_INCLUSIVE_OR_EXPRESSION;
  buff->or_e = ptr1;
  buff->xor_e = ptr2;
  buff->or_e->parent_kind = buff->xor_e->parent_kind =
    NODE_INCLUSIVE_OR_EXPRESSION;
  buff->or_e->parent = buff->xor_e->parent = buff;
  buff->create_symtable = or_create_symtable;
  buff->create_symbol = or_create_symbol;

  return buff;
}

static void
or_create_symtable (struct inclusive_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INCLUSIVE_OR_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_INCLUSIVE_OR_EXPRESSION:
      buff->sym_table =
        ((struct inclusive_or_expression *) (buff->parent))->sym_table;
      break;

    case NODE_LOGICAL_AND_EXPRESSION:
      buff->sym_table =
        ((struct logical_and_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->xor_e != NULL)
    buff->xor_e->create_symtable (buff->xor_e);
  if (buff->or_e != NULL)
    buff->or_e->create_symtable (buff->or_e);
}

static void
or_create_symbol (struct inclusive_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INCLUSIVE_OR_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->xor_e != NULL)
    buff->xor_e->create_symbol (buff->xor_e);
  if (buff->or_e != NULL)
    buff->or_e->create_symbol (buff->or_e);
}
