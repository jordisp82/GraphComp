#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "prim_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_pri_expr_id (prim_expr_t * pe, ast_node_t * ast);
static void sem_pri_expr_const (prim_expr_t * pe, ast_node_t * ast);
static void sem_pri_expr_string (prim_expr_t * pe, ast_node_t * ast);
static void sem_pri_expr_expr (prim_expr_t * pe, ast_node_t * ast);

prim_expr_t *
sem_pri_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_PRIMARY_EXPRESSION (ast->func_ptr));

  prim_expr_t *pe = calloc (1, sizeof (prim_expr_t));
  assert (pe != NULL);

  if (ast->func_ptr == primary_expression_1)
    sem_pri_expr_id (pe, ast);
  else if (ast->func_ptr == primary_expression_2)
    sem_pri_expr_const (pe, ast);
  else if (ast->func_ptr == primary_expression_3)
    sem_pri_expr_string (pe, ast);
  else if (ast->func_ptr == primary_expression_4)
    sem_pri_expr_expr (pe, ast);
  else if (ast->func_ptr == primary_expression_5)
    pe->kind = PREXPR_GENERIC;

  return pe;
}

static void
sem_pri_expr_id (prim_expr_t * pe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pe != NULL);
  assert (ast->func_ptr == primary_expression_1);

  pe->kind = PREXPR_ID;
  pe->child.str = strdup (ast->data);
  assert (pe->child.str != NULL);
}

static void
sem_pri_expr_const (prim_expr_t * pe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pe != NULL);
  assert (ast->func_ptr == primary_expression_2);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  if (ast->children[0]->func_ptr == constant_1)
    {
      pe->kind = PREXPR_CONST_I;
      pe->child.iv = *(long long int *) (ast->children[0]->data);
    }
  else if (ast->children[0]->func_ptr == constant_2)
    {
      pe->kind = PREXPR_CONST_F;
      pe->child.dv = *(double *) (ast->children[0]->data);
    }
  else if (ast->children[0]->func_ptr == constant_3)
    {
      pe->kind = PREXPR_CONST_E;
      pe->child.str = strdup (ast->children[0]->data);
    }
}

static void
sem_pri_expr_string (prim_expr_t * pe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pe != NULL);
  assert (ast->func_ptr == primary_expression_3);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  if (ast->children[0]->func_ptr == string_1)
    {
      pe->kind = PREXPR_STRING;
      pe->child.str = strdup (ast->children[0]->data);
    }
  else if (ast->children[0]->func_ptr == string_2)
    {
      pe->kind = PREXPR_FUNCNAM;
      pe->child.str = strdup (ast->children[0]->data);
    }
}

static void
sem_pri_expr_expr (prim_expr_t * pe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pe != NULL);
  assert (ast->func_ptr == primary_expression_4);

  pe->kind = PREXPR_EXPR;
  /* TODO */
}
