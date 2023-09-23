#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "jump_statement.h"
#include "expression.h"
#include "statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct jump_statement *
jump_statement_1 (const char *str)
{
  assert (str != NULL);

  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_GOTO;
  buff->id = strdup (str);
  assert (buff->id != NULL);

  return buff;
}

struct jump_statement *
jump_statement_2 (void)
{
  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_CONTINUE;

  return buff;
}

struct jump_statement *
jump_statement_3 (void)
{
  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_BREAK;

  return buff;
}

struct jump_statement *
jump_statement_4 (void)
{
  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_RETURN_VOID;

  return buff;
}

struct jump_statement *
jump_statement_5 (void *ptr)
{
  assert (ptr != NULL);

  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_RETURN_EXP;
  buff->exp = ptr;
  buff->exp->parent_kind = NODE_JUMP_STATEMENT;
  buff->exp->parent = buff;

  return buff;
}
