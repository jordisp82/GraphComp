#include <assert.h>
#include <stdlib.h>

#include "statement.h"
#include "labeled_statement.h"
#include "compound_statement.h"
#include "expression_statement.h"
#include "selection_statement.h"
#include "iteration_statement.h"
#include "jump_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct statement *
statement_1 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_LABELED_STATEMENT;
  buff->ls = ptr;
  buff->ls->parent_kind = NODE_STATEMENT;
  buff->ls->parent = buff;

  return buff;
}

struct statement *
statement_2 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_COMPOUND_STATEMENT;
  buff->cs = ptr;
  buff->cs->parent_kind = NODE_STATEMENT;
  buff->cs->parent = buff;

  return buff;
}

struct statement *
statement_3 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_EXPRESSION_STATEMENT;
  buff->es = ptr;
  buff->es->parent_kind = NODE_STATEMENT;
  buff->es->parent = buff;

  return buff;
}

struct statement *
statement_4 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_SELECTION_STATEMENT;
  buff->ss = ptr;
  buff->ss->parent_kind = NODE_STATEMENT;
  buff->ss->parent = buff;

  return buff;
}

struct statement *
statement_5 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_ITERATION_STATEMENT;
  buff->is = ptr;
  buff->is->parent_kind = NODE_STATEMENT;
  buff->is->parent = buff;

  return buff;
}

struct statement *
statement_6 (void *ptr)
{
  assert (ptr != NULL);

  struct statement *buff = calloc (1, sizeof (struct statement));
  assert (buff != NULL);
  buff->kind = NODE_STATEMENT;
  buff->child_kind = NODE_JUMP_STATEMENT;
  buff->js = ptr;
  buff->js->parent_kind = NODE_STATEMENT;
  buff->js->parent = buff;

  return buff;
}
