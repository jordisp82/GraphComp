#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "add_expr.h"
#include "mult_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

add_expr_t *
sem_add_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ADD_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  add_expr_t *ae = calloc (1, sizeof (add_expr_t));
  assert (ae != NULL);

  if (ast->func_ptr == add_expression_1)
    ae->mult = sem_mult_expr (ast->children[0]);
  else
    {
      ae->operand = sem_add_expr (ast->children[0]);
      ae->mult = sem_mult_expr (ast->children[1]);
      if (ast->func_ptr == add_expression_2)
        ae->op = '+';
      else if (ast->func_ptr == add_expression_3)
        ae->op = '-';
    }

  return ae;
}
