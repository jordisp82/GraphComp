#include <assert.h>
#include <stdlib.h>

#include "expression.h"
#include "assignment_expression.h"
#include "primary_expression.h"
#include "postfix_expression.h"
#include "conditional_expression.h"
#include "expression_statement.h"
#include "selection_statement.h"
#include "iteration_statement.h"
#include "jump_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct expression *
expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct expression *buff = calloc (1, sizeof (struct expression));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION;
  buff->ass = ptr;
  buff->ass->parent_kind = NODE_EXPRESSION;
  buff->ass->parent = buff;

  return buff;
}

struct expression *
expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct expression *buff = calloc (1, sizeof (struct expression));
  assert (buff != NULL);
  buff->kind = NODE_EXPRESSION;
  buff->expr = ptr1;
  buff->ass = ptr2;
  buff->expr->parent_kind = buff->ass->parent_kind = NODE_EXPRESSION;
  buff->expr->parent = buff->ass->parent = buff;

  return buff;
}

