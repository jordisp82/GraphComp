#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "logic_and_expr.h"
#include "bit_or_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

logic_and_expr_t *
sem_logic_and_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_LOGIC_AND_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  logic_and_expr_t *lae = calloc (1, sizeof (logic_and_expr_t));
  assert (lae != NULL);

  if (ast->func_ptr == logic_and_expression_1)
    lae->bor = sem_bit_or_expr (ast->children[0]);
  else
    {
      lae->operand = sem_logic_and_expr (ast->children[0]);
      lae->bor = sem_bit_or_expr (ast->children[1]);
      if (ast->func_ptr == logic_and_expression_2)
        lae->op = AND_OP;
    }

  return lae;
}
