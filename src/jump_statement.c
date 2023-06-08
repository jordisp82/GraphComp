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

void
set_jump_statetment_scope (struct jump_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_JUMP_STATEMENT);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_STATEMENT:
        set_statement_scope (buff->parent);
        buff->scope = ((struct statement *) (buff->parent))->scope;
        buff->scope_kind = ((struct statement *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG */
      }
}

void
set_symbol_for_jump_stmt (struct jump_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_JUMP_STATEMENT);

  if (buff->js_kind == JS_RETURN_EXP)
    set_symbol_for_expression (buff->exp);
}
