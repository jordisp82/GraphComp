#include <assert.h>
#include <stdlib.h>

#include "cast_expression.h"
#include "unary_expression.h"
#include "type_name.h"
#include "multiplicative_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ce_create_symtable (struct cast_expression *buff);

struct cast_expression *
cast_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct cast_expression *buff = calloc (1, sizeof (struct cast_expression));
  assert (buff != NULL);
  buff->kind = NODE_CAST_EXPRESSION;
  buff->cast_kind = CAST_NO;
  buff->unary_ex = ptr;
  buff->unary_ex->parent_kind = NODE_CAST_EXPRESSION;
  buff->unary_ex->parent = buff;
  buff->create_symtable = ce_create_symtable;

  return buff;
}

struct cast_expression *
cast_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct cast_expression *buff = calloc (1, sizeof (struct cast_expression));
  assert (buff != NULL);
  buff->kind = NODE_CAST_EXPRESSION;
  buff->cast_kind = CAST_NO;
  buff->tn = ptr1;
  buff->cast_ex = ptr2;
  buff->tn->parent_kind = buff->unary_ex->parent_kind = NODE_CAST_EXPRESSION;
  buff->tn->parent = buff->unary_ex->parent = buff;
  buff->create_symtable = ce_create_symtable;

  return buff;
}

static void
ce_create_symtable (struct cast_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CAST_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_UNARY_EXPRESSION:
      buff->sym_table =
        ((struct unary_expression *) (buff->parent))->sym_table;
      break;

    case NODE_MULTIPLICATIVE_EXPRESSION:
      buff->sym_table =
        ((struct multiplicative_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }
}

#if 0
void
set_cast_expression_scope (struct cast_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CAST_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_CAST_EXPRESSION:
        set_cast_expression_scope (buff->parent);
        buff->scope = ((struct cast_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct cast_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_UNARY_EXPRESSION:
        set_unary_expression_scope (buff->parent);
        buff->scope = ((struct unary_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct unary_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_MULTIPLICATIVE_EXPRESSION:
        set_mult_expression_scope (buff->parent);
        buff->scope =
          ((struct multiplicative_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct multiplicative_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_cast_expression (struct cast_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CAST_EXPRESSION);

  if (buff->cast_kind == CAST_YES)
    set_symbol_for_cast_expression (buff->cast_ex);
  else
    set_symbol_for_unary_expression (buff->unary_ex);
}
#endif
