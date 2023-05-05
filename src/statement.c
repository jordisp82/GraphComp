#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "statement.h"
#include "compound_stmt.h"
#include "expression.h"
#include "cond_expr.h"
#include "declaration.h"
#include "ast.h"

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

  st->child.label = calloc (1, sizeof (label_stmt_t));
  assert (st->child.label != NULL);

  if (ast->func_ptr == labeled_statement_1)
    {
      st->child.label->kind = LABEL_LABEL;
      st->child.label->id = strdup (ast->data);
      assert (st->child.label->id != NULL);
      st->child.label->stmt = sem_statement (ast->children[0]);
    }
  else if (ast->func_ptr == labeled_statement_2)
    {
      st->child.label->kind = LABEL_CASE;
      st->child.label->const_expr = sem_cond_expr (ast->children[0]);
      st->child.label->stmt = sem_statement (ast->children[1]);
    }
  else if (ast->func_ptr == labeled_statement_3)
    {
      st->child.label->kind = LABEL_DEFAULT;
      st->child.label->stmt = sem_statement (ast->children[0]);
    }
}

static void
sem_stmt_comp (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_COMPOUND_STATEMENT (ast->func_ptr));

  st->kind = STMT_COMPOUND;
  st->child.comp = sem_compound_stmt (ast);
}

static void
sem_stmt_expr (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_EXPRESSION_STATEMENT (ast->func_ptr));

  st->kind = STMT_EXPRESSION;
  /* it may be empty */
  if (ast->children != NULL)
    st->child.expr = sem_expression (ast->children[0]);
  else
    st->child.expr = NULL;
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
  st->child.select = calloc (1, sizeof (select_stmt_t));
  assert (st->child.select != NULL);

  if (ast->func_ptr == selection_statement_1)
    {
      st->child.select->kind = SELECT_IF_ELSE;
      st->child.select->expr = sem_expression (ast->children[0]);
      st->child.select->st = sem_statement (ast->children[1]);
      st->child.select->st_e = sem_statement (ast->children[2]);
    }
  else if (ast->func_ptr == selection_statement_2)
    {
      st->child.select->kind = SELECT_IF;
      st->child.select->expr = sem_expression (ast->children[0]);
      st->child.select->st = sem_statement (ast->children[1]);
    }
  else if (ast->func_ptr == selection_statement_3)
    {
      st->child.select->kind = SELECT_SWITCH;
      st->child.select->expr = sem_expression (ast->children[0]);
      st->child.select->st = sem_statement (ast->children[1]);
    }
}

static void
sem_stmt_iter (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_ITERATION_STATEMENT (ast->func_ptr));

  st->child.iter = calloc (1, sizeof (iter_stmt_t));
  assert (st->child.iter != NULL);

  if (ast->func_ptr == iteration_statement_1)
    {
      st->child.iter->kind = ITER_WHILE;
      st->child.iter->expr = sem_expression (ast->children[0]);
      st->child.iter->stmt = sem_statement (ast->children[1]);
    }
  else if (ast->func_ptr == iteration_statement_2)
    {
      st->child.iter->kind = ITER_DO;
      st->child.iter->expr = sem_expression (ast->children[1]);
      st->child.iter->stmt = sem_statement (ast->children[0]);
    }
  else if (ast->func_ptr == iteration_statement_3)
    {
      st->child.iter->kind = ITER_FOR_1;
      st->child.iter->es1 = sem_statement (ast->children[0]);
      st->child.iter->es2 = sem_statement (ast->children[1]);
      st->child.iter->stmt = sem_statement (ast->children[2]);
    }
  else if (ast->func_ptr == iteration_statement_4)
    {
      st->child.iter->kind = ITER_FOR_2;
      st->child.iter->es1 = sem_statement (ast->children[0]);
      st->child.iter->es2 = sem_statement (ast->children[1]);
      st->child.iter->expr = sem_expression (ast->children[2]);
      st->child.iter->stmt = sem_statement (ast->children[3]);
    }
  else if (ast->func_ptr == iteration_statement_5)
    {
      st->child.iter->kind = ITER_FOR_3;
      st->child.iter->decl = sem_declaration (ast->children[0]);
      st->child.iter->es1 = sem_statement (ast->children[1]);
      st->child.iter->stmt = sem_statement (ast->children[2]);
    }
  else if (ast->func_ptr == iteration_statement_6)
    {
      st->child.iter->kind = ITER_FOR_4;
      st->child.iter->decl = sem_declaration (ast->children[0]);
      st->child.iter->es1 = sem_statement (ast->children[1]);
      st->child.iter->expr = sem_expression (ast->children[2]);
      st->child.iter->stmt = sem_statement (ast->children[3]);
    }
}

static void
sem_stmt_jump (statement_t * st, ast_node_t * ast)
{
  assert (st != NULL);
  assert (ast != NULL);
  assert (IS_JUMP_STATEMENT (ast->func_ptr));

  st->kind = STMT_JUMP;
  st->child.jump = calloc (1, sizeof (jump_stmt_t));
  assert (st->child.jump != NULL);

  if (ast->func_ptr == jump_statement_1)
    {
      st->child.jump->kind = JUMP_GOTO;
      st->child.jump->label = strdup (ast->data);
    }
  else if (ast->func_ptr == jump_statement_2)
    st->child.jump->kind = JUMP_CONTINUE;
  else if (ast->func_ptr == jump_statement_3)
    st->child.jump->kind = JUMP_BREAK;
  else if (ast->func_ptr == jump_statement_4)
    st->child.jump->kind = JUMP_RETURN;
  else if (ast->func_ptr == jump_statement_5)
    {
      st->child.jump->kind = JUMP_RETURN;
      st->child.jump->expr = sem_expression (ast->children[0]);
    }
}
