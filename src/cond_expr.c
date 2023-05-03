#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "cond_expr.h"
#include "logic_or_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

cond_expr_t *
sem_cond_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_CONDITIONAL_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  cond_expr_t *ce = calloc (1, sizeof (cond_expr_t));
  assert (ce != NULL);

  ce->op1 = sem_logic_or_expr (ast->children[0]);
  if (ast->func_ptr == conditional_expression_1)
    {
      ce->op2 = /* TODO */ 0;
      ce->op3 = sem_cond_expr (ast->children[2]);
    }

  return ce;
}
