#include <assert.h>
#include <stdlib.h>

#include "logical_or_expression.h"
#include "logical_and_expression.h"
#include "conditional_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void lor_create_symtable (struct logical_or_expression *buff);
static void lor_create_symbol (struct logical_or_expression *buff);

struct logical_or_expression *
logical_or_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct logical_or_expression *buff =
    calloc (1, sizeof (struct logical_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_OR_EXPRESSION;
  buff->and_e = ptr;
  buff->and_e->parent_kind = NODE_LOGICAL_OR_EXPRESSION;
  buff->and_e->parent = buff;
  buff->create_symtable = lor_create_symtable;
  buff->create_symbol = lor_create_symbol;

  return buff;
}

struct logical_or_expression *
logical_or_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct logical_or_expression *buff =
    calloc (1, sizeof (struct logical_or_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_OR_EXPRESSION;
  buff->or_e = ptr1;
  buff->and_e = ptr2;
  buff->or_e->parent_kind = buff->and_e->parent_kind =
    NODE_LOGICAL_OR_EXPRESSION;
  buff->or_e->parent = buff->and_e->parent = buff;
  buff->create_symtable = lor_create_symtable;
  buff->create_symbol = lor_create_symbol;

  return buff;
}

static void
lor_create_symtable (struct logical_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_OR_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_LOGICAL_OR_EXPRESSION:
      buff->sym_table =
        ((struct logical_or_expression *) (buff->parent))->sym_table;
      break;

    case NODE_CONDITIONAL_EXPRESSION:
      buff->sym_table =
        ((struct conditional_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->and_e != NULL)
    buff->and_e->create_symtable (buff->and_e);
  if (buff->or_e != NULL)
    buff->or_e->create_symtable (buff->or_e);
}

static void
lor_create_symbol (struct logical_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_OR_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->and_e != NULL)
    buff->and_e->create_symbol (buff->and_e);
  if (buff->or_e != NULL)
    buff->or_e->create_symbol (buff->or_e);
}
