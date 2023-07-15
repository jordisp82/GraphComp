#include <assert.h>
#include <stdlib.h>

#include "logical_and_expression.h"
#include "inclusive_or_expression.h"
#include "logical_or_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void land_create_symtable (struct logical_and_expression *buff);

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

  return buff;
}

static void
land_create_symtable (struct logical_and_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_AND_EXPRESSION);

  buff->sym_table =
    ((struct logical_or_expression *) (buff->parent))->sym_table;
  if (buff->inc_or != NULL)
    buff->inc_or->create_symtable (buff->inc_or);
  if (buff->log_and != NULL)
    buff->log_and->create_symtable (buff->log_and);
}

#if 0
void
set_logic_and_expression_scope (struct logical_and_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_AND_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_LOGICAL_AND_EXPRESSION:
        set_logic_and_expression_scope (buff->parent);
        buff->scope =
          ((struct logical_and_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct logical_and_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_LOGICAL_OR_EXPRESSION:
        set_logic_or_expression_scope (buff->parent);
        buff->scope =
          ((struct logical_or_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct logical_or_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_logic_and_expression (struct logical_and_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LOGICAL_AND_EXPRESSION);
  assert (buff->inc_or != NULL);

  set_symbol_for_or_expression (buff->inc_or);
  if (buff->log_and != NULL)
    set_symbol_for_logic_and_expression (buff->log_and);
}
#endif
