#include <assert.h>
#include <stdlib.h>

#include "relational_expression.h"
#include "shift_expression.h"
#include "equality_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct relational_expression *
relational_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->sh_ex = ptr;
  buff->sh_ex->parent_kind = NODE_RELATIONAL_EXPRESSION;
  buff->sh_ex->parent = buff;

  return buff;
}

struct relational_expression *
relational_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->relex = ptr1;
  buff->sh_ex = ptr2;
  buff->relex->parent_kind = buff->sh_ex->parent_kind =
    NODE_RELATIONAL_EXPRESSION;
  buff->relex->parent = buff->sh_ex->parent = buff;

  return buff;
}

struct relational_expression *
relational_expression_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->relex = ptr1;
  buff->sh_ex = ptr2;
  buff->relex->parent_kind = buff->sh_ex->parent_kind =
    NODE_RELATIONAL_EXPRESSION;
  buff->relex->parent = buff->sh_ex->parent = buff;

  return buff;
}

struct relational_expression *
relational_expression_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->relex = ptr1;
  buff->sh_ex = ptr2;
  buff->relex->parent_kind = buff->sh_ex->parent_kind =
    NODE_RELATIONAL_EXPRESSION;
  buff->relex->parent = buff->sh_ex->parent = buff;

  return buff;
}

struct relational_expression *
relational_expression_5 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct relational_expression *buff =
    calloc (1, sizeof (struct relational_expression));
  assert (buff != NULL);
  buff->kind = NODE_RELATIONAL_EXPRESSION;
  buff->rel_kind = REL_SHIFT;
  buff->relex = ptr1;
  buff->sh_ex = ptr2;
  buff->relex->parent_kind = buff->sh_ex->parent_kind =
    NODE_RELATIONAL_EXPRESSION;
  buff->relex->parent = buff->sh_ex->parent = buff;

  return buff;
}

void
set_rel_expression_scope (struct relational_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_RELATIONAL_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_RELATIONAL_EXPRESSION:
        set_rel_expression_scope (buff->parent);
        buff->scope =
          ((struct relational_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct relational_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_EQUALITY_EXPRESSION:
        set_equality_expression_scope (buff->parent);
        buff->scope = ((struct equality_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct equality_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
