#include <assert.h>
#include <stdlib.h>

#include "additive_expression.h"
#include "multiplicative_expression.h"
#include "shift_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ae_create_symtable (struct additive_expression *buff);
static void ae_create_symbol (struct additive_expression *buff);

struct additive_expression *
additive_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct additive_expression *buff =
    calloc (1, sizeof (struct additive_expression));
  assert (buff != NULL);
  buff->kind = NODE_ADDITIVE_EXPRESSION;
  buff->add_kind = ADD_NONE;
  buff->mult_ex = ptr;
  buff->mult_ex->parent_kind = NODE_ADDITIVE_EXPRESSION;
  buff->mult_ex->parent = buff;
  buff->create_symtable = ae_create_symtable;
  buff->create_symbol = ae_create_symbol;

  return buff;
}

struct additive_expression *
additive_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct additive_expression *buff =
    calloc (1, sizeof (struct additive_expression));
  assert (buff != NULL);
  buff->kind = NODE_ADDITIVE_EXPRESSION;
  buff->add_kind = ADD_PLUS;
  buff->add_ex = ptr1;
  buff->mult_ex = ptr2;
  buff->add_ex->parent_kind = buff->mult_ex->parent_kind =
    NODE_ADDITIVE_EXPRESSION;
  buff->add_ex->parent = buff->mult_ex->parent = buff;
  buff->create_symtable = ae_create_symtable;
  buff->create_symbol = ae_create_symbol;

  return buff;
}

struct additive_expression *
additive_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct additive_expression *buff =
    calloc (1, sizeof (struct additive_expression));
  assert (buff != NULL);
  buff->kind = NODE_ADDITIVE_EXPRESSION;
  buff->add_kind = ADD_MINUS;
  buff->add_ex = ptr1;
  buff->mult_ex = ptr2;
  buff->add_ex->parent_kind = buff->mult_ex->parent_kind =
    NODE_ADDITIVE_EXPRESSION;
  buff->add_ex->parent = buff->mult_ex->parent = buff;
  buff->create_symtable = ae_create_symtable;
  buff->create_symbol = ae_create_symbol;

  return buff;
}

static void
ae_create_symtable (struct additive_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ADDITIVE_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_ADDITIVE_EXPRESSION:
      buff->sym_table =
        ((struct additive_expression *) (buff->parent))->sym_table;
      break;

    case NODE_SHIFT_EXPRESSION:
      buff->sym_table =
        ((struct shift_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->mult_ex != NULL)
    buff->mult_ex->create_symtable (buff->mult_ex);
  if (buff->add_ex != NULL)
    buff->add_ex->create_symtable (buff->add_ex);
}

static void
ae_create_symbol (struct additive_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ADDITIVE_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->mult_ex != NULL)
    buff->mult_ex->create_symbol (buff->mult_ex);
  if (buff->add_ex != NULL)
    buff->add_ex->create_symbol (buff->add_ex);
}
