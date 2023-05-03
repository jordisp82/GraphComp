#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "postfix_expr.h"
#include "ast.h"
#include "prim_expr.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_postfix_pre (postfix_expr_t * pfe, ast_node_t * ast);
static void sem_postfix_array (postfix_expr_t * pfe, ast_node_t * ast);
static void sem_postfix_func (postfix_expr_t * pfe, ast_node_t * ast);
static void sem_postfix_memb1 (postfix_expr_t * pfe, ast_node_t * ast);
static void sem_postfix_memb2 (postfix_expr_t * pfe, ast_node_t * ast);
static void sem_postfix_incr (postfix_expr_t * pfe, ast_node_t * ast);
static void sem_postfix_decr (postfix_expr_t * pfe, ast_node_t * ast);
static void sem_postfix_clit (postfix_expr_t * pfe, ast_node_t * ast);

postfix_expr_t *
sem_postfix_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_POSTFIX_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  postfix_expr_t *pfe = calloc (1, sizeof (postfix_expr_t));
  assert (pfe != NULL);

  if (ast->func_ptr == postfix_expression_1)
    sem_postfix_pre (pfe, ast);
  else if (ast->func_ptr == postfix_expression_2)
    sem_postfix_array (pfe, ast);
  else if (ast->func_ptr == postfix_expression_3
           || ast->func_ptr == postfix_expression_4)
    sem_postfix_func (pfe, ast);
  else if (ast->func_ptr == postfix_expression_5)
    sem_postfix_memb1 (pfe, ast);
  else if (ast->func_ptr == postfix_expression_6)
    sem_postfix_memb2 (pfe, ast);
  else if (ast->func_ptr == postfix_expression_7)
    sem_postfix_incr (pfe, ast);
  else if (ast->func_ptr == postfix_expression_8)
    sem_postfix_decr (pfe, ast);
  else if (ast->func_ptr == postfix_expression_9
           || ast->func_ptr == postfix_expression_10)
    sem_postfix_clit (pfe, ast);

  return pfe;
}

static void
sem_postfix_pre (postfix_expr_t * pfe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pfe != NULL);
  assert (ast->func_ptr == postfix_expression_1);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  pfe->kind = POSTFIX_PRI;
  pfe->child.pri_expr = sem_pri_expr (ast->children[0]);
}

static void
sem_postfix_array (postfix_expr_t * pfe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pfe != NULL);
  assert (ast->func_ptr == postfix_expression_2);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  pfe->kind = POSTFIX_ARRAY;
  pfe->operand = sem_postfix_expr (ast->children[0]);
  /* TODO pfe->child.expr */
}

static void
sem_postfix_func (postfix_expr_t * pfe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pfe != NULL);
  assert (ast->func_ptr == postfix_expression_3
          || ast->func_ptr == postfix_expression_4);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  pfe->kind = POSTFIX_FUNC;
  pfe->operand = sem_postfix_expr (ast->children[0]);
  if (ast->func_ptr == postfix_expression_4)
    /* TODO */ ;
}

static void
sem_postfix_memb1 (postfix_expr_t * pfe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pfe != NULL);
  assert (ast->func_ptr == postfix_expression_5);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  pfe->kind = POSTFIX_MEMB1;
  pfe->operand = sem_postfix_expr (ast->children[0]);
  pfe->child.id = strdup (ast->data);   /* FIXME no estic segur de si és el pare o el fill */
}

static void
sem_postfix_memb2 (postfix_expr_t * pfe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pfe != NULL);
  assert (ast->func_ptr == postfix_expression_6);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  pfe->kind = POSTFIX_MEMB2;
  pfe->operand = sem_postfix_expr (ast->children[0]);
  pfe->child.id = strdup (ast->data);   /* FIXME no estic segur de si és el pare o el fill */
}

static void
sem_postfix_incr (postfix_expr_t * pfe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pfe != NULL);
  assert (ast->func_ptr == postfix_expression_7);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  pfe->kind = POSTFIX_INCR;
  pfe->operand = sem_postfix_expr (ast->children[0]);
}

static void
sem_postfix_decr (postfix_expr_t * pfe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pfe != NULL);
  assert (ast->func_ptr == postfix_expression_8);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  pfe->kind = POSTFIX_DECR;
  pfe->operand = sem_postfix_expr (ast->children[0]);
}

static void
sem_postfix_clit (postfix_expr_t * pfe, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (pfe != NULL);
  assert (ast->func_ptr == postfix_expression_9
          || ast->func_ptr == postfix_expression_10);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  pfe->kind = POSTFIX_CLIT;
  /* TODO */
}
