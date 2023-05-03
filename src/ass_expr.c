#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "ass_expr.h"
#include "cond_expr.h"
#include "unary_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

ass_expr_t *
sem_ass_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ASSIGNMENT_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  ass_expr_t *ass = calloc (1, sizeof (ass_expr_t));
  assert (ass != NULL);

  if (ast->func_ptr == assignment_expression_1)
    ass->cond = sem_cond_expr (ast->children[0]);
  else if (ast->func_ptr == assignment_expression_2)
    {
      ass->unary = sem_unary_expr (ast->children[0]);
      ass->ass = sem_ass_expr (ast->children[2]);
      ass->op = ast->children[1]->token;
    }

  return ass;
}
