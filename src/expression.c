#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "expression.h"
#include "ass_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

expression_t *
sem_expression (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_EXPRESSION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  expression_t *ex = calloc (1, sizeof (expression_t));
  assert (ex != NULL);

  if (ast->func_ptr == expression_1)
    ex->ass = sem_ass_expr (ast->children[0]);
  else if (ast->func_ptr == expression_2)
    {
      ex->ass = sem_ass_expr (ast->children[1]);
      ex->expr = sem_expression (ast->children[0]);
    }

  return ex;
}
