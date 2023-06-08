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

void
set_expression_stmt_scope (struct expression_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXPRESSION_STATEMENT);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_STATEMENT:
        set_statement_scope (buff->parent);
        buff->scope = ((struct statement *) (buff->parent))->scope;
        buff->scope_kind = ((struct statement *) (buff->parent))->scope_kind;
        break;

      case NODE_ITERATION_STATEMENT:
        set_iteration_stmt_scope (buff->parent);
        buff->scope = ((struct iteration_statement *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct iteration_statement *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_expression_stmt (struct expression_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXPRESSION_STATEMENT);

  if (buff->expr != NULL)
    set_symbol_for_expression (buff->expr);
}
