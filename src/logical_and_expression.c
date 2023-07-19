#include <assert.h>
#include <stdlib.h>

#include "logical_and_expression.h"
#include "inclusive_or_expression.h"
#include "logical_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void land_create_symtable (struct logical_and_expression *buff);
static void land_create_symbol (struct logical_and_expression *buff);

struct logical_and_expression *
logical_and_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct logical_and_expression *buff =
    calloc (1, sizeof (struct logical_and_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_AND_EXPRESSION;
  buff->inc_or = ptr;
  buff->inc_or->parent_kind = NODE_LOGICAL_AND_EXPRESSION;
  buff->inc_or->parent = buff;
  buff->create_symtable = land_create_symtable;
  buff->create_symbol = land_create_symbol;

  return buff;
}

struct logical_and_expression *
logical_and_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct logical_and_expression *buff =
    calloc (1, sizeof (struct logical_and_expression));
  assert (buff != NULL);
  buff->kind = NODE_LOGICAL_AND_EXPRESSION;
  buff->log_and = ptr1;
  buff->inc_or = ptr2;
  buff->log_and->parent_kind = buff->inc_or->parent_kind =
    NODE_LOGICAL_AND_EXPRESSION;
  buff->log_and->parent = buff->inc_or->parent = buff;
  buff->create_symtable = land_create_symtable;
  buff->create_symbol = land_create_symbol;

  return buff;
}

static void
land_create_symtable (struct logical_and_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_AND_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_LOGICAL_AND_EXPRESSION:
      buff->sym_table =
        ((struct logical_and_expression *) (buff->parent))->sym_table;
      break;

    case NODE_LOGICAL_OR_EXPRESSION:
      buff->sym_table =
        ((struct logical_or_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->inc_or != NULL)
    buff->inc_or->create_symtable (buff->inc_or);
  if (buff->log_and != NULL)
    buff->log_and->create_symtable (buff->log_and);
}

static void
land_create_symbol (struct logical_and_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_AND_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->inc_or != NULL)
    buff->inc_or->create_symbol (buff->inc_or);
  if (buff->log_and != NULL)
    buff->log_and->create_symbol (buff->log_and);
}
