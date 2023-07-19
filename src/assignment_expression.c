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

static void ass_create_symtable (struct assignment_expression *buff);
static void ass_create_symbol (struct assignment_expression *buff);

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
  buff->create_symtable = ass_create_symtable;
  buff->create_symbol = ass_create_symbol;

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
  buff->create_symtable = ass_create_symtable;
  buff->create_symbol = ass_create_symbol;

  return buff;
}

static void
ass_create_symtable (struct assignment_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ASSIGNMENT_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_ARGUMENT_EXPRESSION_LIST:
      buff->sym_table =
        ((struct argument_expression_list *) (buff->parent))->sym_table;
      break;

    case NODE_EXPRESSION:
      buff->sym_table = ((struct expression *) (buff->parent))->sym_table;
      break;

    case NODE_DIRECT_DECLARATOR:
      buff->sym_table =
        ((struct direct_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_DIRECT_ABSTRACT_DECLARATOR:
      buff->sym_table =
        ((struct direct_abstract_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_INITIALIZER:
      buff->sym_table = ((struct initializer *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->cond_e != NULL)
    buff->cond_e->create_symtable (buff->cond_e);
  if (buff->un_expr != NULL)
    buff->un_expr->create_symtable (buff->un_expr);
  if (buff->ass_op != NULL)
    buff->ass_op->create_symtable (buff->ass_op);
  if (buff->ass_e != NULL)
    buff->ass_e->create_symtable (buff->ass_e);
}

static void
ass_create_symbol (struct assignment_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ASSIGNMENT_EXPRESSION);
  assert (buff->sym_table != NULL);

  if (buff->cond_e != NULL)
    buff->cond_e->create_symbol (buff->cond_e);
  if (buff->un_expr != NULL)
    buff->un_expr->create_symbol (buff->un_expr);
  if (buff->ass_op != NULL)
    buff->ass_op->create_symbol (buff->ass_op);
  if (buff->ass_e != NULL)
    buff->ass_e->create_symbol (buff->ass_e);
}

#if 0
void
set_assignment_expression_scope (struct assignment_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ASSIGNMENT_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
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
        buff->scope_kind =
          ((struct initializer *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_assignment_expression (struct assignment_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ASSIGNMENT_EXPRESSION);

  if (buff->cond_e != NULL)
    set_symbol_for_cond_expression (buff->cond_e);      /* TODO */
  if (buff->un_expr != NULL)
    set_symbol_for_unary_expression (buff->un_expr);
  if (buff->ass_e != NULL)
    set_symbol_for_assignment_expression (buff->ass_e);
}
#endif
