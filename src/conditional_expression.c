#include <assert.h>
#include <stdlib.h>

#include "conditional_expression.h"
#include "logical_or_expression.h"
#include "expression.h"
#include "assignment_expression.h"
#include "constant_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ce_create_symtable (struct conditional_expression *buff);

struct conditional_expression *
conditional_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct conditional_expression *buff =
    calloc (1, sizeof (struct conditional_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr = ptr;
  buff->l_expr->parent_kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr->parent = buff;
  buff->create_symtable = ce_create_symtable;

  return buff;
}

struct conditional_expression *
conditional_expression_2 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct conditional_expression *buff =
    calloc (1, sizeof (struct conditional_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr = ptr1;
  buff->expr = ptr2;
  buff->cond_e = ptr3;
  buff->l_expr->parent_kind = buff->expr->parent_kind =
    buff->cond_e->parent_kind = NODE_CONDITIONAL_EXPRESSION;
  buff->l_expr->parent = buff->expr->parent = buff->cond_e->parent = buff;
  buff->create_symtable = ce_create_symtable;

  return buff;
}

static void
ce_create_symtable (struct conditional_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CONDITIONAL_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_ASSIGNMENT_EXPRESSION:
      buff->sym_table =
        ((struct assignment_expression *) (buff->parent))->sym_table;
      break;

    case NODE_CONSTANT_EXPRESSION:
      buff->sym_table =
        ((struct constant_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->l_expr != NULL)
    buff->l_expr->create_symtable (buff->l_expr);
  if (buff->expr != NULL)
    buff->expr->create_symtable (buff->expr);
  if (buff->cond_e != NULL)
    buff->cond_e->create_symtable (buff->cond_e);
}

#if 0
void
set_cond_expression_scope (struct conditional_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CONDITIONAL_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_CONDITIONAL_EXPRESSION:
        set_cond_expression_scope (buff->parent);
        buff->scope =
          ((struct conditional_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct conditional_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_ASSIGNMENT_EXPRESSION:
        set_assignment_expression_scope (buff->parent);
        buff->scope =
          ((struct assignment_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct assignment_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_CONSTANT_EXPRESSION:
        set_const_expression_scope (buff->parent);
        buff->scope = ((struct constant_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct constant_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_cond_expression (struct conditional_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CONDITIONAL_EXPRESSION);
  assert (buff->l_expr != NULL);

  set_symbol_for_logic_or_expression (buff->l_expr);
  if (buff->expr != NULL)
    set_symbol_for_expression (buff->expr);
  if (buff->cond_e != NULL)
    set_symbol_for_cond_expression (buff->cond_e);
}
#endif
