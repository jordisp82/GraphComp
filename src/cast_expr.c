#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "cast_expr.h"
#include "unary_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

cast_expr_t *
sem_cast_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_CAST_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  cast_expr_t *ce = calloc (1, sizeof (cast_expr_t));
  assert (ce != NULL);

  if (ast->func_ptr == cast_expression_1)
    {
      ce->kind = CSEXPR_UNARY;
      ce->unary = sem_unary_expr (ast->children[0]);
    }
  else if (ast->func_ptr == cast_expression_2)
    {
      ce->kind = CSEXPR_CAST;
      ce->cast = sem_cast_expr (ast->children[1]);
      /* TODO type name */
    }

  return ce;
}
