#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "bit_and_expr.h"
#include "equal_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

bit_and_expr_t *
sem_bit_and_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ADD_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  bit_and_expr_t *bae = calloc (1, sizeof (bit_and_expr_t));
  assert (bae != NULL);

  if (ast->func_ptr == and_expression_1)
    bae->eq = sem_equal_expr (ast->children[0]);
  else
    {
      bae->operand = sem_bit_and_expr (ast->children[0]);
      bae->eq = sem_equal_expr (ast->children[1]);
      if (ast->func_ptr == and_expression_2)
        bae->op = '&';
    }

  return bae;
}
