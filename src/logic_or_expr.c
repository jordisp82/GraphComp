#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "logic_or_expr.h"
#include "logic_and_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

logic_or_expr_t *
sem_logic_or_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_LOGIC_OR_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  logic_or_expr_t *loe = calloc (1, sizeof (logic_or_expr_t));
  assert (loe != NULL);

  if (ast->func_ptr == logic_or_expression_1)
    loe->land = sem_logic_and_expr (ast->children[0]);
  else
    {
      loe->operand = sem_logic_or_expr (ast->children[0]);
      loe->land = sem_logic_and_expr (ast->children[1]);
      if (ast->func_ptr == logic_or_expression_2)
        loe->op = OR_OP;
    }

  return loe;
}
