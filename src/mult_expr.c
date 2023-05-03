#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "mult_expr.h"
#include "cast_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

mult_expr_t *
sem_mult_expr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_MULT_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  mult_expr_t *me = calloc (1, sizeof (mult_expr_t));
  assert (me != NULL);

  if (ast->func_ptr == mult_expression_1)
    me->cast = sem_cast_expr (ast->children[0]);
  else
    {
      me->operand = sem_mult_expr (ast->children[0]);
      me->cast = sem_cast_expr (ast->children[1]);
      if (ast->func_ptr == mult_expression_2)
        me->op = '*';
      else if (ast->func_ptr == mult_expression_3)
        me->op = '/';
      else if (ast->func_ptr == mult_expression_4)
        me->op = '%';
    }

  return me;
}
