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
static void ce_create_symbol (struct cast_expression *buff);

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
  buff->create_symbol = ce_create_symbol;

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
  buff->create_symbol = ce_create_symbol;

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

    case NODE_CAST_EXPRESSION:
      buff->sym_table =
        ((struct cast_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  switch (buff->cast_kind)
    {
    case CAST_NO:
      buff->unary_ex->create_symtable (buff->unary_ex);
      break;

    case CAST_YES:
      buff->cast_ex->create_symtable (buff->cast_ex);
      buff->tn->create_symtable (buff->tn);
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
ce_create_symbol (struct cast_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CAST_EXPRESSION);
  assert (buff->sym_table != NULL);

  switch (buff->cast_kind)
    {
    case CAST_NO:
      buff->unary_ex->create_symbol (buff->unary_ex);
      break;

    case CAST_YES:
      buff->cast_ex->create_symbol (buff->cast_ex);
      buff->tn->create_symbol (buff->tn);
      break;

    default:
      ;                         /* BUG! */
    }
}
