#include <assert.h>
#include <stdlib.h>

#include "expression_statement.h"
#include "expression.h"
#include "statement.h"
#include "iteration_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct expression_statement *
expression_statement_1 (void)
{
  struct expression_statement *buff =
    calloc (1, sizeof (struct expression_statement));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION_STATEMENT;
  buff->es_kind = ES_EMPTY;

  return buff;
}

struct expression_statement *
expression_statement_2 (void *ptr)
{
  struct expression_statement *buff =
    calloc (1, sizeof (struct expression_statement));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION_STATEMENT;
  buff->es_kind = ES_EXPRESSION;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_EXPRESSION_STATEMENT;
  buff->expr->parent = buff;

  return buff;
}

