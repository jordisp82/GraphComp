#include <assert.h>
#include <stdlib.h>

#include "unary_operator.h"
#include "unary_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void u_create_symtable (struct unary_operator *buff);
static void u_create_symbol (struct unary_operator *buff);

struct unary_operator *
unary_operator_1 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_AMPERSAND;
  buff->create_symtable = u_create_symtable;
  buff->create_symbol = u_create_symbol;

  return buff;
}

struct unary_operator *
unary_operator_2 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_STAR;
  buff->create_symtable = u_create_symtable;
  buff->create_symbol = u_create_symbol;

  return buff;
}

struct unary_operator *
unary_operator_3 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_PLUS;
  buff->create_symtable = u_create_symtable;
  buff->create_symbol = u_create_symbol;

  return buff;
}

struct unary_operator *
unary_operator_4 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_DASH;
  buff->create_symtable = u_create_symtable;
  buff->create_symbol = u_create_symbol;

  return buff;
}

struct unary_operator *
unary_operator_5 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_TILDE;
  buff->create_symtable = u_create_symtable;
  buff->create_symbol = u_create_symbol;

  return buff;
}

struct unary_operator *
unary_operator_6 (void)
{
  struct unary_operator *buff = calloc (1, sizeof (struct unary_operator));
  assert (buff != NULL);
  buff->kind = NODE_UNARY_OPERATOR;
  buff->un_op = UNOP_EXCLAMATION;
  buff->create_symtable = u_create_symtable;
  buff->create_symbol = u_create_symbol;

  return buff;
}

static void
u_create_symtable (struct unary_operator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_UNARY_OPERATOR);

  buff->sym_table = ((struct unary_expression *) (buff->parent))->sym_table;
}

static void
u_create_symbol (struct unary_operator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_UNARY_OPERATOR);
  assert (buff->sym_table != NULL);

  /* nothing to do */
}
