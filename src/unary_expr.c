#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "unary_expr.h"
#include "ast.h"
#include "postfix_expr.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_unary_pfe (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_inc (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_dec (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_unop (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_sizeof1 (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_sizeof2 (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_alignof (unary_expr_t * uex, ast_node_t * ast);

unary_expr_t *
sem_unary_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_UNARY_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  unary_expr_t *uex = calloc (1, sizeof (unary_expr_t));
  assert (uex != NULL);

  if (ast->func_ptr == unary_expression_1)
    sem_unary_pfe (uex, ast);
  else if (ast->func_ptr == unary_expression_2)
    sem_unary_inc (uex, ast);
  else if (ast->func_ptr == unary_expression_3)
    sem_unary_dec (uex, ast);
  else if (ast->func_ptr == unary_expression_4)
    sem_unary_unop (uex, ast);
  else if (ast->func_ptr == unary_expression_5)
    sem_unary_sizeof1 (uex, ast);
  else if (ast->func_ptr == unary_expression_6)
    sem_unary_sizeof2 (uex, ast);
  else if (ast->func_ptr == unary_expression_7)
    sem_unary_alignof (uex, ast);

  return uex;
}

static void sem_unary_pfe (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_inc (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_dec (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_unop (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_sizeof1 (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_sizeof2 (unary_expr_t * uex, ast_node_t * ast);
static void sem_unary_alignof (unary_expr_t * uex, ast_node_t * ast);
