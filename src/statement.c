#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "statement.h"
#include "sem_t.h"
#include "ast.h"
#include "compound_stmt.h"
#include "declaration.h"

#if 0
#include "statement.h"
#include "compound_stmt.h"
#include "expression.h"
#include "cond_expr.h"
#include "ast.h"
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_stmt_labeled (statement_t * st, ast_node_t * ast);
static void sem_stmt_comp (statement_t * st, ast_node_t * ast);
static void sem_stmt_expr (statement_t * st, ast_node_t * ast);
static void sem_stmt_select (statement_t * st, ast_node_t * ast);
static void sem_stmt_iter (statement_t * st, ast_node_t * ast);
static void sem_stmt_jump (statement_t * st, ast_node_t * ast);

statement_t *
sem_statement (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_STATEMENT (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  statement_t *st = calloc (1, sizeof (statement_t));
  assert (st != NULL);
  st->node = ast;

  if (IS_LABELED_STATEMENT (ast->children[0]->func_ptr))
    sem_stmt_labeled (st, ast->children[0]);
  else if (IS_COMPOUND_STATEMENT (ast->children[0]->func_ptr))
    sem_stmt_comp (st, ast->children[0]);
  else if (IS_EXPRESSION_STATEMENT (ast->children[0]->func_ptr))
    sem_stmt_expr (st, ast->children[0]);
  else if (IS_SELECTION_STATEMENT (ast->children[0]->func_ptr))
    sem_stmt_select (st, ast->children[0]);
  else if (IS_ITERATION_STATEMENT (ast->children[0]->func_ptr))
    sem_stmt_iter (st, ast->children[0]);
  else if (IS_JUMP_STATEMENT (ast->children[0]->func_ptr))
    sem_stmt_jump (st, ast->children[0]);
  /* else abort */

  return st;
}

static void
sem_stmt_labeled (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_LABELED_STATEMENT (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  st->kind = STMT_LABELED;
  st->label = calloc (1, sizeof (label_stmt_t));
  assert (st->label != NULL);

  if (ast->func_ptr == labeled_statement_1)
    {
      st->label->kind = LABEL_LABEL;
      st->label->str = strdup (ast->data);
      assert (st->label->str != NULL);
      st->label->stmt = sem_statement (ast->children[0]);
      st->label->parent = st;
      st->label->stmt->parent = st->label;
      st->label->stmt->parent_kind = PARENT_LABEL_STMT;
    }
  else if (ast->func_ptr == labeled_statement_2)
    {
      st->label->kind = LABEL_CASE;
      // st->label->expr = sem_cond_expr (ast->children[0]);
      st->label->stmt = sem_statement (ast->children[1]);
      st->label->parent = st;
      st->label->stmt->parent = st->label;
      st->label->stmt->parent_kind = PARENT_LABEL_STMT;
    }
  else if (ast->func_ptr == labeled_statement_3)
    {
      st->label->kind = LABEL_DEFAULT;
      st->label->stmt = sem_statement (ast->children[0]);
      st->label->parent = st;
      st->label->stmt->parent = st->label;
      st->label->stmt->parent_kind = PARENT_LABEL_STMT;
    }
  /* else abort */
}

static void
sem_stmt_comp (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_COMPOUND_STATEMENT (ast->func_ptr));

  st->kind = STMT_COMPOUND;
  st->comp = sem_compound_stmt (ast);
  st->comp->parent_kind = PARENT_STATEMENT;
  st->comp->parent = st;
}

static void
sem_stmt_expr (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_EXPRESSION_STATEMENT (ast->func_ptr));

  st->kind = STMT_EXPRESSION;
#if 0
  // TODO
  /* it may be empty */
  if (ast->children != NULL)
    st->child.expr = sem_expression (ast->children[0]);
  else
    st->child.expr = NULL;
  // parent, parent_kind
#endif
}

static void
sem_stmt_select (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_SELECTION_STATEMENT (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  st->kind = STMT_SELECTION;
  st->select = calloc (1, sizeof (select_stmt_t));
  assert (st->select != NULL);

  if (ast->func_ptr == selection_statement_1)
    {
      st->select->kind = SELECT_IF_ELSE;
      // TODO st->select->expr = sem_expression (ast->children[0]);
      st->select->st1 = sem_statement (ast->children[1]);
      st->select->st2 = sem_statement (ast->children[2]);
      st->select->st1->parent = st->select->st2->parent = st->select;
      st->select->st1->parent_kind = st->select->st2->parent_kind =
        PARENT_IF_STMT;
    }
  else if (ast->func_ptr == selection_statement_2)
    {
      st->select->kind = SELECT_IF;
      // TODO st->select->expr = sem_expression (ast->children[0]);
      st->select->st1 = sem_statement (ast->children[1]);
      st->select->st1->parent = st->select->st2->parent = st->select;
      st->select->st1->parent_kind = st->select->st2->parent_kind =
        PARENT_IF_STMT;
    }
  else if (ast->func_ptr == selection_statement_3)
    {
      st->select->kind = SELECT_SWITCH;
      // TODO st->select->expr = sem_expression (ast->children[0]);
      st->select->st1 = sem_statement (ast->children[1]);
      st->select->st1->parent = st->select->st2->parent = st->select;
      st->select->st1->parent_kind = st->select->st2->parent_kind =
        PARENT_SWITCH_STMT;
    }
  /* else abort */
}

static void
sem_stmt_iter (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_ITERATION_STATEMENT (ast->func_ptr));

  st->kind = STMT_ITERATION;
  st->iter = calloc (1, sizeof (iter_stmt_t));
  assert (st->iter != NULL);

  if (ast->func_ptr == iteration_statement_1)
    {
      st->iter->kind = ITER_WHILE;
      // TODO st->iter->expr = sem_expression (ast->children[0]);
      st->iter->stmt = sem_statement (ast->children[1]);
    }
  else if (ast->func_ptr == iteration_statement_2)
    {
      st->iter->kind = ITER_DO;
      // TODO st->iter->expr = sem_expression (ast->children[1]);
      st->iter->stmt = sem_statement (ast->children[0]);
      st->iter->stmt->parent = st->iter;
    }
  else if (ast->func_ptr == iteration_statement_3)
    {
      st->iter->kind = ITER_FOR_1;
      st->iter->es1 = sem_statement (ast->children[0]);
      st->iter->es1->parent = st->iter;
      st->iter->es2 = sem_statement (ast->children[1]);
      st->iter->es2->parent = st->iter;
      st->iter->stmt = sem_statement (ast->children[2]);
      st->iter->stmt->parent = st->iter;
    }
  else if (ast->func_ptr == iteration_statement_4)
    {
      st->iter->kind = ITER_FOR_2;
      st->iter->es1 = sem_statement (ast->children[0]);
      st->iter->es1->parent = st->iter;
      st->iter->es2 = sem_statement (ast->children[1]);
      st->iter->es2->parent = st->iter;
      // TODO st->iter->expr = sem_expression (ast->children[2]);
      st->iter->stmt = sem_statement (ast->children[3]);
      st->iter->stmt->parent = st->iter;
    }
  else if (ast->func_ptr == iteration_statement_5)
    {
      st->iter->kind = ITER_FOR_3;
      st->iter->decl = sem_declaration (ast->children[0]);
      st->iter->decl->parent_kind = PARENT_ITER_STMT;
      st->iter->decl->parent = st->iter;
      st->iter->es1 = sem_statement (ast->children[1]);
      st->iter->es1->parent = st->iter;
      st->iter->stmt = sem_statement (ast->children[2]);
      st->iter->stmt->parent = st->iter;
    }
  else if (ast->func_ptr == iteration_statement_6)
    {
      st->iter->kind = ITER_FOR_4;
      st->iter->decl = sem_declaration (ast->children[0]);
      st->iter->decl->parent_kind = PARENT_ITER_STMT;
      st->iter->decl->parent = st->iter;
      st->iter->es1 = sem_statement (ast->children[1]);
      st->iter->es1->parent = st->iter;
      // TODO st->iter->expr = sem_expression (ast->children[2]);
      st->iter->stmt = sem_statement (ast->children[3]);
      st->iter->stmt->parent = st->iter;
    }
  /* else abort */
}

static void
sem_stmt_jump (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_JUMP_STATEMENT (ast->func_ptr));

  st->kind = STMT_JUMP;
  st->jump = calloc (1, sizeof (jump_stmt_t));
  assert (st->jump != NULL);

  if (ast->func_ptr == jump_statement_1)
    {
      st->jump->kind = JUMP_GOTO;
      st->jump->label = strdup (ast->data);
    }
  else if (ast->func_ptr == jump_statement_2)
    st->jump->kind = JUMP_CONTINUE;
  else if (ast->func_ptr == jump_statement_3)
    st->jump->kind = JUMP_BREAK;
  else if (ast->func_ptr == jump_statement_4)
    st->jump->kind = JUMP_RETURN;
  else if (ast->func_ptr == jump_statement_5)
    {
      st->jump->kind = JUMP_RETURN;
      // TODO st->jump->expr = sem_expression (ast->children[0]);
    }
  /* else abort */
  st->jump->parent = st;
}
