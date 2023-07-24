#include <assert.h>
#include <stdlib.h>

#include "multiplicative_expression.h"
#include "cast_expression.h"
#include "additive_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void m_create_symtable (struct multiplicative_expression *buff);
static void m_create_symbol (struct multiplicative_expression *buff);

struct multiplicative_expression *
multiplicative_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_NONE;
  buff->cast_ex = ptr;
  buff->cast_ex->parent_kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->cast_ex->parent = buff;
  buff->create_symtable = m_create_symtable;
  buff->create_symbol = m_create_symbol;

  return buff;
}

struct multiplicative_expression *
multiplicative_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_STAR;
  buff->mult_ex = ptr1;
  buff->cast_ex = ptr2;
  buff->mult_ex->parent_kind = buff->cast_ex->parent_kind =
    NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_ex->parent = buff->cast_ex->parent = buff;
  buff->create_symtable = m_create_symtable;
  buff->create_symbol = m_create_symbol;

  return buff;
}

struct multiplicative_expression *
multiplicative_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_SLASH;
  buff->mult_ex = ptr1;
  buff->cast_ex = ptr2;
  buff->mult_ex->parent_kind = buff->cast_ex->parent_kind =
    NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_ex->parent = buff->cast_ex->parent = buff;
  buff->create_symtable = m_create_symtable;
  buff->create_symbol = m_create_symbol;

  return buff;
}

struct multiplicative_expression *
multiplicative_expression_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct multiplicative_expression *buff =
    calloc (1, sizeof (struct multiplicative_expression));
  assert (buff != NULL);
  buff->kind = NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_kind = MULT_MODULO;
  buff->mult_ex = ptr1;
  buff->cast_ex = ptr2;
  buff->mult_ex->parent_kind = buff->cast_ex->parent_kind =
    NODE_MULTIPLICATIVE_EXPRESSION;
  buff->mult_ex->parent = buff->cast_ex->parent = buff;
  buff->create_symtable = m_create_symtable;
  buff->create_symbol = m_create_symbol;

  return buff;
}

static void
m_create_symtable (struct multiplicative_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_MULTIPLICATIVE_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_MULTIPLICATIVE_EXPRESSION:
      buff->sym_table =
        ((struct multiplicative_expression *) (buff->parent))->sym_table;
      break;

    case NODE_ADDITIVE_EXPRESSION:
      buff->sym_table =
        ((struct additive_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->cast_ex != NULL)
    buff->cast_ex->create_symtable (buff->cast_ex);
  if (buff->mult_ex != NULL)
    buff->mult_ex->create_symtable (buff->mult_ex);
}

static void
m_create_symbol (struct multiplicative_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_MULTIPLICATIVE_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->cast_ex != NULL)
    buff->cast_ex->create_symbol (buff->cast_ex);
  if (buff->mult_ex != NULL)
    buff->mult_ex->create_symbol (buff->mult_ex);
}
