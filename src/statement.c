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

static void s_create_symtable (struct statement *buff);

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
  buff->create_symtable = s_create_symtable;

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
  buff->create_symtable = s_create_symtable;

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
  buff->create_symtable = s_create_symtable;

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
  buff->create_symtable = s_create_symtable;

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
  buff->create_symtable = s_create_symtable;

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
  buff->create_symtable = s_create_symtable;

  return buff;
}

static void
s_create_symtable (struct statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STATEMENT);

  switch (buff->parent_kind)
    {
    case NODE_LABELED_STATEMENT:
      buff->sym_table =
        ((struct labeled_statement *) (buff->parent))->sym_table;
      break;

    case NODE_BLOCK_ITEM:
      buff->sym_table = ((struct block_item *) (buff->parent))->sym_table;
      break;

    case NODE_SELECTION_STATEMENT:
      buff->sym_table =
        ((struct selection_statement *) (buff->parent))->sym_table;
      break;

    case NODE_ITERATION_STATEMENT:
      buff->sym_table =
        ((struct iteration_statement *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  switch (buff->child_kind)
    {
    case NODE_LABELED_STATEMENT:
      buff->ls->create_symtable (buff->ls);
      break;

    case NODE_COMPOUND_STATEMENT:
      buff->cs->create_symtable (buff->cs);
      break;

    case NODE_EXPRESSION_STATEMENT:
      buff->es->create_symtable (buff->es);
      break;

    case NODE_SELECTION_STATEMENT:
      buff->ss->create_symtable (buff->ss);
      break;

    case NODE_ITERATION_STATEMENT:
      buff->is->create_symtable (buff->is);
      break;

    case NODE_JUMP_STATEMENT:
      buff->js->create_symtable (buff->js);
      break;

    default:
      ;                         /* BUG! */
    }
}

#if 0
void
set_statement_scope (struct statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STATEMENT);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
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
        ;                       /* BUG! */
      }
}

void
set_symbol_for_statement (struct statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STATEMENT);

  switch (buff->child_kind)
    {
    case NODE_LABELED_STATEMENT:
      /* nothing to do */
      break;

    case NODE_COMPOUND_STATEMENT:
      set_symbol_for_compound_stmt (buff->cs);
      break;

    case NODE_EXPRESSION_STATEMENT:
      set_symbol_for_expression_stmt (buff->es);
      break;

    case NODE_SELECTION_STATEMENT:
      set_symbol_for_selection_stmt (buff->ss);
      break;

    case NODE_ITERATION_STATEMENT:
      set_symbol_for_iteration_stmt (buff->is);
      break;

    case NODE_JUMP_STATEMENT:
      set_symbol_for_jump_stmt (buff->js);
      break;

    default:
      ;                         /* BUG! */
    }
}
#endif
