#include <assert.h>
#include <stdlib.h>

#include "assignment_expression.h"
#include "conditional_expression.h"
#include "unary_expression.h"
#include "assignment_operator.h"
#include "expression.h"
#include "argument_expression_list.h"
#include "initializer.h"
#include "direct_declarator.h"
#include "direct_abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct assignment_expression *
assignment_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct assignment_expression *buff =
    calloc (1, sizeof (struct assignment_expression));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->cond_e = ptr;
  buff->cond_e->parent_kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->cond_e->parent = buff;

  return buff;
}

struct assignment_expression *
assignment_expression_2 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct assignment_expression *buff =
    calloc (1, sizeof (struct assignment_expression));
  assert (buff != NULL);
  buff->kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->un_expr = ptr1;
  buff->ass_op = ptr2;
  buff->ass_e = ptr3;
  buff->un_expr->parent_kind = buff->ass_op->parent_kind =
    buff->ass_e->parent_kind = NODE_ASSIGNMENT_EXPRESSION;
  buff->un_expr->parent = buff->ass_op->parent = buff->ass_e->parent = buff;

  return buff;
}

void
set_assignment_expression_scope (struct assignment_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ASSIGNMENT_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_ARGUMENT_EXPRESSION_LIST:
      set_argument_expression_list_scope (buff->parent);
      buff->scope =
        ((struct argument_expression_list *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct argument_expression_list *) (buff->parent))->scope_kind;
      break;

    case NODE_EXPRESSION:
      set_expression_scope (buff->parent);
      buff->scope = ((struct expression *) (buff->parent))->scope;
      buff->scope_kind = ((struct expression *) (buff->parent))->scope_kind;
      break;

    case NODE_DIRECT_DECLARATOR:
      set_direct_declarator_scope (buff->parent);
      buff->scope = ((struct direct_declarator *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct direct_declarator *) (buff->parent))->scope_kind;
      break;

    case NODE_DIRECT_ABSTRACT_DECLARATOR:
      set_direct_abs_declarator_scope (buff->parent);
      buff->scope =
        ((struct direct_abstract_declarator *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct direct_abstract_declarator *) (buff->parent))->scope_kind;
      break;

    case NODE_INITIALIZER:
      set_initializer_scope (buff->parent);
      buff->scope = ((struct initializer *) (buff->parent))->scope;
      buff->scope_kind = ((struct initializer *) (buff->parent))->scope_kind;
      break;

    default:
      ;                         /* BUG! */
    }
}
