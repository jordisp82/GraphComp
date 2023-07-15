#include <assert.h>
#include <stdlib.h>

#include "selection_statement.h"
#include "expression.h"
#include "statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ss_create_symtable (struct selection_statement *buff);

struct selection_statement *
selection_statement_1 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct selection_statement *buff =
    calloc (1, sizeof (struct selection_statement));
  assert (buff != NULL);
  buff->kind = NODE_SELECTION_STATEMENT;
  buff->ss_kind = SS_IF_ELSE;
  buff->ex = ptr1;
  buff->st1 = ptr2;
  buff->st2 = ptr3;
  buff->ex->parent_kind = buff->st1->parent_kind = buff->st2->parent_kind =
    NODE_SELECTION_STATEMENT;
  buff->ex->parent = buff->st1->parent = buff->st2->parent = buff;
  buff->create_symtable = ss_create_symtable;

  return buff;
}

struct selection_statement *
selection_statement_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct selection_statement *buff =
    calloc (1, sizeof (struct selection_statement));
  assert (buff != NULL);
  buff->kind = NODE_SELECTION_STATEMENT;
  buff->ss_kind = SS_IF;
  buff->ex = ptr1;
  buff->st1 = ptr2;
  buff->ex->parent_kind = buff->st1->parent_kind = NODE_SELECTION_STATEMENT;
  buff->ex->parent = buff->st1->parent = buff;
  buff->create_symtable = ss_create_symtable;

  return buff;
}

struct selection_statement *
selection_statement_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct selection_statement *buff =
    calloc (1, sizeof (struct selection_statement));
  assert (buff != NULL);
  buff->kind = NODE_SELECTION_STATEMENT;
  buff->ss_kind = SS_SWITCH;
  buff->ex = ptr1;
  buff->st1 = ptr2;
  buff->ex->parent_kind = buff->st1->parent_kind = NODE_SELECTION_STATEMENT;
  buff->ex->parent = buff->st1->parent = buff;
  buff->create_symtable = ss_create_symtable;

  return buff;
}

static void
ss_create_symtable (struct selection_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_SELECTION_STATEMENT);

  buff->sym_table = ((struct statement *) (buff->parent))->sym_table;
  /* TODO children */
}

#if 0
void
set_selection_stmt_scope (struct selection_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_SELECTION_STATEMENT);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_STATEMENT:
        set_statement_scope (buff->parent);
        buff->scope = ((struct statement *) (buff->parent))->scope;
        buff->scope_kind = ((struct statement *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_selection_stmt (struct selection_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_SELECTION_STATEMENT);
  assert (buff->ex != NULL);
  assert (buff->st1 != NULL);

  set_symbol_for_expression (buff->ex);
  set_symbol_for_statement (buff->st1);
  if (buff->st2 != NULL)
    set_symbol_for_statement (buff->st2);
}
#endif
