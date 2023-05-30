#include <assert.h>
#include <stdlib.h>

#include "constant_expression.h"
#include "conditional_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct constant_expression *
constant_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct constant_expression *buff =
    calloc (1, sizeof (struct constant_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT_EXPRESSION;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_CONSTANT_EXPRESSION;
  buff->expr->parent = buff;

  return buff;
}

void
set_const_expression_scope (struct constant_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CONSTANT_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_STRUCT_DECLARATOR:
      ;

    case NODE_ENUMERATOR:
      ;

    case NODE_ALIGNMENT_SPECIFIER:
      ;

    case NODE_DESIGNATOR:
      ;

    case NODE_STATIC_ASSERT_DECLARATION:
      ;

    case NODE_LABELED_STATEMENT:
      ;

    default:
      ;                         /* BUG */
    }
}
