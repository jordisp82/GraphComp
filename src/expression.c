#include <assert.h>
#include <stdlib.h>

#include "expression.h"
#include "assignment_expression.h"
#include "primary_expression.h"
#include "postfix_expression.h"
#include "conditional_expression.h"
#include "expression_statement.h"
#include "selection_statement.h"
#include "iteration_statement.h"
#include "jump_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ex_create_symtable (struct expression *buff);

struct expression *
expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct expression *buff = calloc (1, sizeof (struct expression));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION;
  buff->ass = ptr;
  buff->ass->parent_kind = NODE_EXPRESSION;
  buff->ass->parent = buff;
  buff->create_symtable = ex_create_symtable;

  return buff;
}

struct expression *
expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct expression *buff = calloc (1, sizeof (struct expression));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION;
  buff->expr = ptr1;
  buff->ass = ptr2;
  buff->expr->parent_kind = buff->ass->parent_kind = NODE_EXPRESSION;
  buff->expr->parent = buff->ass->parent = buff;
  buff->create_symtable = ex_create_symtable;

  return buff;
}

static void
ex_create_symtable (struct expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_EXPRESSION:
      buff->sym_table = ((struct expression *) (buff->parent))->sym_table;
      break;

    case NODE_PRIMARY_EXPRESSION:
      buff->sym_table =
        ((struct primary_expression *) (buff->parent))->sym_table;
      break;

    case NODE_POSTFIX_EXPRESSION:
      buff->sym_table =
        ((struct postfix_expression *) (buff->parent))->sym_table;
      break;

    case NODE_CONDITIONAL_EXPRESSION:
      buff->sym_table =
        ((struct conditional_expression *) (buff->parent))->sym_table;
      break;

    case NODE_EXPRESSION_STATEMENT:
      buff->sym_table =
        ((struct expression_statement *) (buff->parent))->sym_table;
      break;

    case NODE_SELECTION_STATEMENT:
      buff->sym_table =
        ((struct selection_statement *) (buff->parent))->sym_table;
      break;

    case NODE_ITERATION_STATEMENT:
      buff->sym_table =
        ((struct iteration_statement *) (buff->parent))->sym_table;
      break;

    case NODE_JUMP_STATEMENT:
      buff->sym_table = ((struct jump_statement *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->expr != NULL)
    buff->expr->create_symtable (buff->expr);
  if (buff->ass != NULL)
    buff->ass->create_symtable (buff->ass);
}

#if 0
void
set_expression_scope (struct expression *buff)
{
  assert (buff != NULL);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_EXPRESSION:
        set_expression_scope (buff->parent);
        buff->scope = ((struct expression *) (buff->parent))->scope;
        buff->scope_kind = ((struct expression *) (buff->parent))->scope_kind;
        break;

      case NODE_PRIMARY_EXPRESSION:
        set_primary_expression_scope (buff->parent);
        buff->scope = ((struct primary_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct primary_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_POSTFIX_EXPRESSION:
        set_postfix_expression_scope (buff->parent);
        buff->scope = ((struct postfix_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct postfix_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_CONDITIONAL_EXPRESSION:
        set_cond_expression_scope (buff->parent);
        buff->scope =
          ((struct conditional_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct conditional_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_EXPRESSION_STATEMENT:
        set_expression_stmt_scope (buff->parent);
        buff->scope = ((struct expression_statement *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct expression_statement *) (buff->parent))->scope_kind;
        break;

      case NODE_SELECTION_STATEMENT:
        set_selection_stmt_scope (buff->parent);
        buff->scope = ((struct selection_statement *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct selection_statement *) (buff->parent))->scope_kind;
        break;

      case NODE_ITERATION_STATEMENT:
        set_iteration_stmt_scope (buff->parent);
        buff->scope = buff->parent;
        buff->scope_kind = NODE_ITERATION_STATEMENT;
        break;

      case NODE_JUMP_STATEMENT:
        buff->scope = ((struct jump_statement *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct jump_statement *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_expression (struct expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXPRESSION);
  assert (buff->ass != NULL);

  set_symbol_for_assignment_expression (buff->ass);
  if (buff->expr != NULL)
    set_symbol_for_expression (buff->expr);
}
#endif
