#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "primary_expression.h"
#include "constant.h"
#include "string_symbol.h"
#include "expression.h"
#include "postfix_expression.h"
#include "translation_unit.h"
#include "compound_statement.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void p_create_symtable (struct primary_expression *buff);
static void p_create_symbol (struct primary_expression *buff);

struct primary_expression *
primary_expression_1 (const char *str)
{
  assert (str != NULL);

  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_IDENT;
  buff->id = strdup (str);
  assert (buff->id != NULL);
  buff->create_symtable = p_create_symtable;
  buff->create_symbol = p_create_symbol;

  return buff;
}

struct primary_expression *
primary_expression_2 (void *ptr)
{
  assert (ptr != NULL);

  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_CONST;
  buff->c = ptr;
  buff->c->parent_kind = NODE_PRIMARY_EXPRESSION;
  buff->c->parent = buff;
  buff->create_symtable = p_create_symtable;
  buff->create_symbol = p_create_symbol;

  return buff;
}

struct primary_expression *
primary_expression_3 (void *ptr)
{
  assert (ptr != NULL);

  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_STRING;
  buff->s = ptr;
  buff->s->parent_kind = NODE_PRIMARY_EXPRESSION;
  buff->s->parent = buff;
  buff->create_symtable = p_create_symtable;
  buff->create_symbol = p_create_symbol;

  return buff;
}

struct primary_expression *
primary_expression_4 (void *ptr)
{
  assert (ptr != NULL);

  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_EX;
  buff->e = ptr;
  buff->e->parent_kind = NODE_PRIMARY_EXPRESSION;
  buff->e->parent = buff;
  buff->create_symtable = p_create_symtable;

  return buff;
}

struct primary_expression *
primary_expression_5 (void *ptr __attribute__((unused)))
{
  struct primary_expression *buff =
    calloc (1, sizeof (struct primary_expression));
  assert (buff != NULL);
  buff->kind = NODE_PRIMARY_EXPRESSION;
  buff->priex_kind = PRIEX_GS;
  buff->create_symtable = p_create_symtable;
  buff->create_symbol = p_create_symbol;

  return buff;
}

static void
p_create_symtable (struct primary_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PRIMARY_EXPRESSION);

  buff->sym_table = ((struct postfix_expression *) (buff->parent))->sym_table;
  switch (buff->priex_kind)
    {
    case PRIEX_IDENT:
    case PRIEX_GS:
      break;

    case PRIEX_CONST:
      if (buff->c != NULL)
        buff->c->create_symtable (buff->c);
      break;

    case PRIEX_STRING:
      if (buff->s != NULL)
        buff->s->create_symtable (buff->s);
      break;

    case PRIEX_EX:
      if (buff->e != NULL)
        buff->e->create_symtable (buff->e);
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
p_create_symbol (struct primary_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PRIMARY_EXPRESSION);
  assert (buff->sym_table != NULL);

  avl_node_t *node = NULL;

  switch (buff->priex_kind)
    {
    case PRIEX_IDENT:
      node = avl_search (buff->sym_table->ord, buff->id);
      if (node != NULL)
        buff->sym = node->value;
      break;

    case PRIEX_CONST:
      buff->c->create_symbol (buff->c);
      break;

    case PRIEX_STRING:
    case PRIEX_GS:
      break;                    /* nothing to do */

    case PRIEX_EX:
      buff->e->create_symbol (buff->e);
      break;

    default:
      ;                         /* BUG! */
    }
}
