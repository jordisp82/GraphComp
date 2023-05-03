#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "bit_xor_expr.h"
#include "bit_and_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

bit_xor_expr_t *
sem_bit_xor_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_XOR_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  bit_xor_expr_t *xor = calloc (1, sizeof (bit_xor_expr_t));
  assert (xor != NULL);

  if (ast->func_ptr == xor_expression_1)
    xor->band = sem_bit_and_expr (ast->children[0]);
  else
    {
      xor->operand = sem_bit_xor_expr (ast->children[0]);
      xor->band = sem_bit_and_expr (ast->children[1]);
      if (ast->func_ptr == xor_expression_2)
        xor->op = '^';
    }

  return xor;
}
