#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "equal_expr.h"
#include "rel_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

equal_expr_t *
sem_equal_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_EQUALITY_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  equal_expr_t *ee = calloc (1, sizeof (equal_expr_t));
  assert (ee != NULL);

  if (ast->func_ptr == equality_expression_1)
    ee->rel = sem_rel_expr (ast->children[0]);
  else
    {
      ee->operand = sem_equal_expr (ast->children[0]);
      ee->rel = sem_rel_expr (ast->children[1]);
      if (ast->func_ptr == equality_expression_2)
        ee->op = EQ_OP;
      else if (ast->func_ptr == equality_expression_3)
        ee->op = NE_OP;
    }

  return ee;
}
