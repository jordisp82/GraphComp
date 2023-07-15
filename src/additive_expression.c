#include <assert.h>
#include <stdlib.h>

#include "additive_expression.h"
#include "multiplicative_expression.h"
#include "shift_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ae_create_symtable (struct additive_expression *buff);

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

#if 0
void
set_add_expression_scope (struct additive_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ADDITIVE_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_ADDITIVE_EXPRESSION:
        set_add_expression_scope (buff->parent);
        buff->scope = ((struct additive_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct additive_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_SHIFT_EXPRESSION:
        set_shift_expression_scope (buff->parent);
        buff->scope = ((struct shift_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct shift_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_additive_expression (struct additive_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ADDITIVE_EXPRESSION);
  assert (buff->mult_ex != NULL);

  set_symbol_for_mult_expression (buff->mult_ex);
  if (buff->add_ex != NULL)
    set_symbol_for_additive_expression (buff->add_ex);
}
#endif
