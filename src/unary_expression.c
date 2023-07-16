#include <assert.h>
#include <stdlib.h>

#include "unary_expression.h"
#include "unary_operator.h"
#include "cast_expression.h"
#include "postfix_expression.h"
#include "type_name.h"
#include "assignment_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void u_create_symtable (struct unary_expression *buff);

struct unary_expression *
unary_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct unary_expression *buff =
    calloc (1, sizeof (struct unary_expression));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_EXPRESSION;
  buff->unary_kind = UNARY_POSTFIX;
  buff->pex = ptr;
  buff->pex->parent_kind = NODE_UNARY_EXPRESSION;
  buff->pex->parent = buff;
  buff->create_symtable = u_create_symtable;

  return buff;
}

struct unary_expression *
unary_expression_2 (void *ptr)
{
  assert (ptr != NULL);

  struct unary_expression *buff =
    calloc (1, sizeof (struct unary_expression));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_EXPRESSION;
  buff->unary_kind = UNARY_INC;
  buff->unex = ptr;
  buff->unex->parent_kind = NODE_UNARY_EXPRESSION;
  buff->unex->parent = buff;
  buff->create_symtable = u_create_symtable;

  return buff;
}

struct unary_expression *
unary_expression_3 (void *ptr)
{
  assert (ptr != NULL);

  struct unary_expression *buff =
    calloc (1, sizeof (struct unary_expression));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_EXPRESSION;
  buff->unary_kind = UNARY_DEC;
  buff->unex = ptr;
  buff->unex->parent_kind = NODE_UNARY_EXPRESSION;
  buff->unex->parent = buff;
  buff->create_symtable = u_create_symtable;

  return buff;
}

struct unary_expression *
unary_expression_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct unary_expression *buff =
    calloc (1, sizeof (struct unary_expression));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_EXPRESSION;
  buff->unary_kind = UNARY_OP;
  buff->unop = ptr1;
  buff->cex = ptr2;
  buff->unop->parent_kind = buff->cex->parent_kind = NODE_UNARY_EXPRESSION;
  buff->unop->parent = buff->cex->parent = buff;
  buff->create_symtable = u_create_symtable;

  return buff;
}

struct unary_expression *
unary_expression_5 (void *ptr)
{
  assert (ptr != NULL);

  struct unary_expression *buff =
    calloc (1, sizeof (struct unary_expression));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_EXPRESSION;
  buff->unary_kind = UNARY_SIZEOF1;
  buff->unex = ptr;
  buff->unex->parent_kind = NODE_UNARY_EXPRESSION;
  buff->unex->parent = buff;
  buff->create_symtable = u_create_symtable;

  return buff;
}

struct unary_expression *
unary_expression_6 (void *ptr)
{
  assert (ptr != NULL);

  struct unary_expression *buff =
    calloc (1, sizeof (struct unary_expression));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_EXPRESSION;
  buff->unary_kind = UNARY_SIZEOF2;
  buff->tn = ptr;
  buff->tn->parent_kind = NODE_UNARY_EXPRESSION;
  buff->tn->parent = buff;
  buff->create_symtable = u_create_symtable;

  return buff;
}

struct unary_expression *
unary_expression_7 (void *ptr)
{
  assert (ptr != NULL);

  struct unary_expression *buff =
    calloc (1, sizeof (struct unary_expression));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_EXPRESSION;
  buff->unary_kind = UNARY_ALIGNOF;
  buff->tn = ptr;
  buff->tn->parent_kind = NODE_UNARY_EXPRESSION;
  buff->tn->parent = buff;
  buff->create_symtable = u_create_symtable;

  return buff;
}

static void
u_create_symtable (struct unary_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_UNARY_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_CAST_EXPRESSION:
      buff->sym_table =
        ((struct cast_expression *) (buff->parent))->sym_table;
      break;

    case NODE_ASSIGNMENT_EXPRESSION:
      buff->sym_table =
        ((struct assignment_expression *) (buff->parent))->sym_table;
      break;

    case NODE_UNARY_EXPRESSION:
      buff->sym_table =
        ((struct unary_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->pex != NULL)
    buff->pex->create_symtable (buff->pex);
  if (buff->unex != NULL)
    buff->unex->create_symtable (buff->unex);
  if (buff->unop != NULL)
    buff->unop->create_symtable (buff->unop);
  if (buff->cex != NULL)
    buff->cex->create_symtable (buff->cex);
  if (buff->tn != NULL)
    buff->tn->create_symtable (buff->tn);
}

#if 0
void
set_unary_expression_scope (struct unary_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_UNARY_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_CAST_EXPRESSION:
        set_cast_expression_scope (buff->parent);
        buff->scope = ((struct cast_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct cast_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_ASSIGNMENT_EXPRESSION:
        set_assignment_expression_scope (buff->parent);
        buff->scope =
          ((struct assignment_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct assignment_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_UNARY_EXPRESSION:
        set_unary_expression_scope (buff->parent);
        buff->scope = ((struct unary_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct unary_expression *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_unary_expression (struct unary_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_UNARY_EXPRESSION);

  switch (buff->unary_kind)
    {
    case UNARY_POSTFIX:
      set_symbol_for_postfix_expression (buff->pex);
      break;

    case UNARY_INC:
    case UNARY_DEC:
    case UNARY_SIZEOF1:
      set_symbol_for_unary_expression (buff->unex);
      break;

    case UNARY_OP:
      /* TODO cast expression */
      break;

    case UNARY_SIZEOF2:
    case UNARY_ALIGNOF:
      /* nothing to do */
      break;

    default:
      ;                         /* BUG! */
    }
}
#endif
