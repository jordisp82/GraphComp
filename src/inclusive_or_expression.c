#include <assert.h>
#include <stdlib.h>

#include "inclusive_or_expression.h"
#include "exclusive_or_expression.h"
#include "logical_and_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void or_create_symtable (struct inclusive_or_expression *buff);

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

  return buff;
}

static void
or_create_symtable (struct inclusive_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INCLUSIVE_OR_EXPRESSION);

  buff->sym_table =
    ((struct logical_and_expression *) (buff->parent))->sym_table;
  if (buff->xor_e != NULL)
    buff->xor_e->create_symtable (buff->xor_e);
  if (buff->or_e != NULL)
    buff->or_e->create_symtable (buff->or_e);
}

#if 0
void
set_or_expression_scope (struct inclusive_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INCLUSIVE_OR_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_INCLUSIVE_OR_EXPRESSION:
        set_or_expression_scope (buff->parent);
        buff->scope =
          ((struct inclusive_or_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct inclusive_or_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_LOGICAL_AND_EXPRESSION:
        set_logic_and_expression_scope (buff->parent);
        buff->scope =
          ((struct logical_and_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct logical_and_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_or_expression (struct inclusive_or_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INCLUSIVE_OR_EXPRESSION);
  assert (buff->xor_e != NULL);

  set_symbol_for_xor_expression (buff->xor_e);
  if (buff->or_e != NULL)
    set_symbol_for_or_expression (buff->or_e);
}
#endif
