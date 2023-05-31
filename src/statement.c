#include <assert.h>
#include <stdlib.h>

#include "statement.h"
#include "labeled_statement.h"
#include "compound_statement.h"
#include "expression_statement.h"
#include "selection_statement.h"
#include "iteration_statement.h"
#include "jump_statement.h"
#include "block_item.h"

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

void
set_statement_scope (struct statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STATEMENT);

  if (buff->scope != NULL && buff->scope_kind != NODE_UNDEFINED)
    return;

  switch (buff->parent_kind)
    {
    case NODE_LABELED_STATEMENT:
      set_labeled_stmt_scope (buff->parent);
      buff->scope = ((struct labeled_statement *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct labeled_statement *) (buff->parent))->scope_kind;
      break;

    case NODE_BLOCK_ITEM:
      set_block_item_scope (buff->parent);
      buff->scope = ((struct block_item *) (buff->parent))->scope;
      buff->scope_kind = ((struct block_item *) (buff->parent))->scope_kind;
      break;

    case NODE_SELECTION_STATEMENT:
      set_selection_stmt_scope (buff->parent);
      buff->scope = ((struct selection_statement *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct selection_statement *) (buff->parent))->scope_kind;
      break;

    case NODE_ITERATION_STATEMENT:
      set_iteration_stmt_scope (buff->parent);
      buff->scope = ((struct iteration_statement *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct iteration_statement *) (buff->parent))->scope_kind;
      break;

    default:
      ;                         /* BUG! */
    }
}
