#include <assert.h>
#include <stdlib.h>

#include "expression_statement.h"
#include "expression.h"
#include "statement.h"
#include "iteration_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void es_create_symtable (struct expression_statement *buff);
static void es_create_symbol (struct expression_statement *buff);

struct expression_statement *
expression_statement_1 (void)
{
  struct expression_statement *buff =
    calloc (1, sizeof (struct expression_statement));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION_STATEMENT;
  buff->es_kind = ES_EMPTY;
  buff->create_symtable = es_create_symtable;
  buff->create_symbol = es_create_symbol;

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
  buff->create_symtable = es_create_symtable;
  buff->create_symbol = es_create_symbol;

  return buff;
}

static void
es_create_symtable (struct expression_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXPRESSION_STATEMENT);

  switch (buff->parent_kind)
    {
    case NODE_STATEMENT:
      buff->sym_table = ((struct statement *) (buff->parent))->sym_table;
      break;

    case NODE_ITERATION_STATEMENT:
      buff->sym_table =
        ((struct iteration_statement *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->expr != NULL)
    buff->expr->create_symtable (buff->expr);
}

static void
es_create_symbol (struct expression_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXPRESSION_STATEMENT);
  assert (buff->sym_table != NULL);

  if (buff->expr != NULL)
    buff->expr->create_symbol (buff->expr);
}
