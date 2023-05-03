#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "bit_or_expr.h"
#include "bit_xor_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

bit_or_expr_t *
sem_bit_or_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_OR_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  bit_or_expr_t *boe = calloc (1, sizeof (bit_or_expr_t));
  assert (boe != NULL);

  if (ast->func_ptr == or_expression_1)
    boe->xor = sem_bit_xor_expr (ast->children[0]);
  else
    {
      boe->operand = sem_bit_or_expr (ast->children[0]);
      boe->xor = sem_bit_xor_expr (ast->children[1]);
      if (ast->func_ptr == or_expression_2)
        boe->op = '|';
    }

  return boe;
}
