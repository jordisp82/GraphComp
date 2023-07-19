#include <assert.h>
#include <stdlib.h>

#include "equality_expression.h"
#include "relational_expression.h"
#include "and_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void eq_create_symtable (struct equality_expression *buff);
static void eq_create_symbol (struct equality_expression *buff);

struct equality_expression *
equality_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct equality_expression *buff =
    calloc (1, sizeof (struct equality_expression));
  assert (buff != NULL);
  buff->kind = NODE_EQUALITY_EXPRESSION;
  buff->eq_kind = EQ_NO_OP;
  buff->rexp = ptr;
  buff->rexp->parent_kind = NODE_EQUALITY_EXPRESSION;
  buff->rexp->parent = buff;
  buff->create_symtable = eq_create_symtable;
  buff->create_symbol = eq_create_symbol;

  return buff;
}

struct equality_expression *
equality_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct equality_expression *buff =
    calloc (1, sizeof (struct equality_expression));
  assert (buff != NULL);
  buff->kind = NODE_EQUALITY_EXPRESSION;
  buff->eq_kind = EQ_EQUAL;
  buff->eqex = ptr1;
  buff->rexp = ptr2;
  buff->eqex->parent_kind = buff->rexp->parent_kind =
    NODE_EQUALITY_EXPRESSION;
  buff->eqex->parent = buff->rexp->parent = buff;
  buff->create_symtable = eq_create_symtable;
  buff->create_symbol = eq_create_symbol;

  return buff;
}

struct equality_expression *
equality_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct equality_expression *buff =
    calloc (1, sizeof (struct equality_expression));
  assert (buff != NULL);
  buff->kind = NODE_EQUALITY_EXPRESSION;
  buff->eq_kind = EQ_NOT_EQUAL;
  buff->eqex = ptr1;
  buff->rexp = ptr2;
  buff->eqex->parent_kind = buff->rexp->parent_kind =
    NODE_EQUALITY_EXPRESSION;
  buff->eqex->parent = buff->rexp->parent = buff;
  buff->create_symtable = eq_create_symtable;
  buff->create_symbol = eq_create_symbol;

  return buff;
}

static void
eq_create_symtable (struct equality_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EQUALITY_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_EQUALITY_EXPRESSION:
      buff->sym_table =
        ((struct equality_expression *) (buff->parent))->sym_table;
      break;

    case NODE_AND_EXPRESSION:
      buff->sym_table = ((struct and_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->rexp != NULL)
    buff->rexp->create_symtable (buff->rexp);
  if (buff->eqex != NULL)
    buff->eqex->create_symtable (buff->eqex);
}

static void
eq_create_symbol (struct equality_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EQUALITY_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->rexp != NULL)
    buff->rexp->create_symbol (buff->rexp);
  if (buff->eqex != NULL)
    buff->eqex->create_symbol (buff->eqex);
}
