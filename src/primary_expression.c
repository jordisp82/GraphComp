#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "primary_expression.h"
#include "constant.h"
#include "string_symbol.h"
#include "expression.h"
#include "postfix_expression.h"
#include "translation_unit.h"
#include "compound_statement.h"

#ifndef NULL
#define NULL ((void*)0)
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
