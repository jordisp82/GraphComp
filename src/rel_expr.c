#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "rel_expr.h"
#include "bitw_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

rel_expr_t *
sem_rel_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_RELATIONAL_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  rel_expr_t *re = calloc (1, sizeof (rel_expr_t));
  assert (re != NULL);

  if (ast->func_ptr == relational_expression_1)
    re->shift = sem_bitw_expr (ast->children[0]);
  else
    {
      re->operand = sem_rel_expr (ast->children[0]);
      re->shift = sem_bitw_expr (ast->children[1]);
      if (ast->func_ptr == relational_expression_2)
        re->op = '<';
      else if (ast->func_ptr == relational_expression_3)
        re->op = '>';
      else if (ast->func_ptr == relational_expression_4)
        re->op = LE_OP;
      else if (ast->func_ptr == relational_expression_5)
        re->op = GE_OP;
    }

  return re;
}
