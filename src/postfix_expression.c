#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "postfix_expression.h"
#include "expression.h"
#include "argument_expression_list.h"
#include "type_name.h"
#include "initializer_list.h"
#include "primary_expression.h"
#include "unary_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct postfix_expression *
postfix_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_PRIMARY;
  buff->pex = ptr;
  buff->pex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pex->parent = buff;

  return buff;
}

struct postfix_expression *
postfix_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_ARRAY;
  buff->pfex = ptr1;
  buff->ex = ptr2;
  buff->pfex->parent_kind = buff->ex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff->ex->parent = buff;

  return buff;
}

struct postfix_expression *
postfix_expression_3 (void *ptr)
{
  assert (ptr != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_FUNCTION;
  buff->pfex = ptr;
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;

  return buff;
}

struct postfix_expression *
postfix_expression_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_FUNCTION;
  buff->pfex = ptr1;
  buff->ael = ptr2;
  buff->pfex->parent_kind = buff->ael->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff->ael->parent = buff;

  return buff;
}

struct postfix_expression *
postfix_expression_5 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_FIELD1;
  buff->pfex = ptr1;
  buff->id = strdup (str);
  assert (buff->id != NULL);
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;

  return buff;
}

struct postfix_expression *
postfix_expression_6 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_FIELD2;
  buff->pfex = ptr1;
  buff->id = strdup (str);
  assert (buff->id != NULL);
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;

  return buff;
}

struct postfix_expression *
postfix_expression_7 (void *ptr)
{
  assert (ptr != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_INC;
  buff->pfex = ptr;
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;

  return buff;
}

struct postfix_expression *
postfix_expression_8 (void *ptr)
{
  assert (ptr != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_DEC;
  buff->pfex = ptr;
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;

  return buff;
}

struct postfix_expression *
postfix_expression_9 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_COMP_LIT;
  buff->comp_lit.tn = ptr1;
  buff->comp_lit.il = ptr2;
  buff->comp_lit.tn->parent_kind = buff->comp_lit.il->parent_kind =
    buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->comp_lit.tn->parent = buff->comp_lit.il->parent = buff->pfex->parent =
    buff;

  return buff;
}

struct postfix_expression *
postfix_expression_10 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_COMP_LIT;
  buff->comp_lit.tn = ptr1;
  buff->comp_lit.il = ptr2;
  buff->comp_lit.tn->parent_kind = buff->comp_lit.il->parent_kind =
    buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->comp_lit.tn->parent = buff->comp_lit.il->parent = buff->pfex->parent =
    buff;

  return buff;
}

void
set_postfix_expression_scope (struct postfix_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_POSTFIX_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_UNARY_EXPRESSION:
        set_unary_expression_scope (buff->parent);
        buff->scope = ((struct unary_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct unary_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_POSTFIX_EXPRESSION:
        set_postfix_expression_scope (buff->parent);
        buff->scope = ((struct postfix_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct postfix_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

#if 0
void
fill_in_symtable_postfix_expr (struct postfix_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_POSTFIX_EXPRESSION);

  switch (buff->pf_kind)
    {
    case POSTFIX_PRIMARY:
      fill_in_symtable_pri_expr (buff->pex);
      break;

    case POSTFIX_ARRAY:
      fill_in_symtable_postfix_expr (buff->pfex);
      fill_in_symtable_expression (buff->ex);
      break;

    case POSTFIX_FUNCTION:
      fill_in_symtable_postfix_expr (buff->pfex);
      if (buff->ael != NULL)
        ;

    case POSTFIX_FIELD1:
    case POSTFIX_FIELD2:
      /* TODO */
#if 0
      fill_in_symtable_postfix_expr (buff->pfex);
      (void) look_for_id_in_symtable (buff);
#endif
      break;

    case POSTFIX_INC:
    case POSTFIX_DEC:
      fill_in_symtable_postfix_expr (buff->pfex);
      break;

    case POSTFIX_COMP_LIT:
      /* nothing to do */
      break;
    }
}
#endif
