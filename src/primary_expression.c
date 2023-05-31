#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "primary_expression.h"
#include "constant.h"
#include "string_symbol.h"
#include "expression.h"
#include "postfix_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

#if 0
static int look_for_id_in_symtable (struct primary_expression *buff);
#endif

struct primary_expression *
primary_expression_1 (const char *str)
{
  assert (str != NULL);

  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_IDENT;
  buff->id = strdup (str);
  assert (buff->id != NULL);

  return buff;
}

struct primary_expression *
primary_expression_2 (void *ptr)
{
  assert (ptr != NULL);

  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_CONST;
  buff->c = ptr;
  buff->c->parent_kind = NODE_PRIMARY_EXPRESSION;
  buff->c->parent = buff;

  return buff;
}

struct primary_expression *
primary_expression_3 (void *ptr)
{
  assert (ptr != NULL);

  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_STRING;
  buff->s = ptr;
  buff->s->parent_kind = NODE_PRIMARY_EXPRESSION;
  buff->s->parent = buff;

  return buff;
}

struct primary_expression *
primary_expression_4 (void *ptr)
{
  assert (ptr != NULL);

  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_EX;
  buff->e = ptr;
  buff->e->parent_kind = NODE_PRIMARY_EXPRESSION;
  buff->e->parent = buff;

  return buff;
}

struct primary_expression *
primary_expression_5 (void *ptr __attribute__((unused)))
{
  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_GS;

  return buff;
}

#if 0
static int
look_for_id_in_symtable (struct primary_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PRIMARY_EXPRESSION);
  assert (buff->priex_kind == PRIEX_IDENT);

  /*
   * We need to locate the first parent
   * with an associated symbol table.
   * This can be:
   * - a compount statement
   * - a translation unit
   */

  // TODO

  return 0;
}
#endif

void
set_primary_expression_scope (struct primary_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PRIMARY_EXPRESSION);

  if (buff->scope != NULL && buff->scope_kind != NODE_UNDEFINED)
    return;

  switch (buff->parent_kind)
    {
    case NODE_POSTFIX_EXPRESSION:
      set_postfix_expression_scope (buff->parent);
      buff->scope = ((struct postfix_expression *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct postfix_expression *) (buff->parent))->scope_kind;
      break;

    default:
      ;                         /* BUG! */
    }
}
