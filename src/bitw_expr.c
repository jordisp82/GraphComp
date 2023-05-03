#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "bitw_expr.h"
#include "add_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

bitw_expr_t *
sem_bitw_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_SHIFT_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  bitw_expr_t *be = calloc (1, sizeof (bitw_expr_t));
  assert (be != NULL);

  if (ast->func_ptr == shift_expression_1)
    be->add = sem_add_expr (ast->children[0]);
  else
    {
      be->operand = sem_bitw_expr (ast->children[0]);
      be->add = sem_add_expr (ast->children[1]);
      if (ast->func_ptr == shift_expression_2)
        be->op = LEFT_OP;
      else if (ast->func_ptr == shift_expression_3)
        be->op = RIGHT_OP;
    }

  return be;
}
