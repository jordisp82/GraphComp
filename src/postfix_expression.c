#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "postfix_expression.h"
#include "expression.h"
#include "argument_expression_list.h"
#include "type_name.h"
#include "initializer_list.h"
#include "primary_expression.h"
#include "unary_expression.h"
#include "compound_statement.h"
#include "translation_unit.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void pe_create_symtable (struct postfix_expression *buff);
static void pe_create_symbol (struct postfix_expression *buff);
static void pe_create_symbol_field (struct postfix_expression *buff);

struct postfix_expression *
postfix_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_PRIMARY;
  buff->pex = ptr;
  buff->pex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pex->parent = buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

struct postfix_expression *
postfix_expression_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_ARRAY;
  buff->pfex = ptr1;
  buff->ex = ptr2;
  buff->pfex->parent_kind = buff->ex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff->ex->parent = buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

struct postfix_expression *
postfix_expression_3 (void *ptr)
{
  assert (ptr != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_FUNCTION;
  buff->pfex = ptr;
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

struct postfix_expression *
postfix_expression_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_FUNCTION;
  buff->pfex = ptr1;
  buff->ael = ptr2;
  buff->pfex->parent_kind = buff->ael->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff->ael->parent = buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

struct postfix_expression *
postfix_expression_5 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_FIELD1;
  buff->pfex = ptr1;
  buff->id = strdup (str);
  assert (buff->id != NULL);
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

struct postfix_expression *
postfix_expression_6 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_FIELD2;
  buff->pfex = ptr1;
  buff->id = strdup (str);
  assert (buff->id != NULL);
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

struct postfix_expression *
postfix_expression_7 (void *ptr)
{
  assert (ptr != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_INC;
  buff->pfex = ptr;
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

struct postfix_expression *
postfix_expression_8 (void *ptr)
{
  assert (ptr != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_DEC;
  buff->pfex = ptr;
  buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->pfex->parent = buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

struct postfix_expression *
postfix_expression_9 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_COMP_LIT;
  buff->comp_lit.tn = ptr1;
  buff->comp_lit.il = ptr2;
  buff->comp_lit.tn->parent_kind = buff->comp_lit.il->parent_kind =
    buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->comp_lit.tn->parent = buff->comp_lit.il->parent = buff->pfex->parent =
    buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

struct postfix_expression *
postfix_expression_10 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct postfix_expression *buff =
    calloc (1, sizeof (struct postfix_expression));
  assert (buff != NULL);
  buff->kind = NODE_POSTFIX_EXPRESSION;
  buff->pf_kind = POSTFIX_COMP_LIT;
  buff->comp_lit.tn = ptr1;
  buff->comp_lit.il = ptr2;
  buff->comp_lit.tn->parent_kind = buff->comp_lit.il->parent_kind =
    buff->pfex->parent_kind = NODE_POSTFIX_EXPRESSION;
  buff->comp_lit.tn->parent = buff->comp_lit.il->parent = buff->pfex->parent =
    buff;
  buff->create_symtable = pe_create_symtable;
  buff->create_symbol = pe_create_symbol;

  return buff;
}

static void
pe_create_symtable (struct postfix_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_POSTFIX_EXPRESSION);

  switch (buff->parent_kind)
    {
    case NODE_UNARY_EXPRESSION:
      buff->sym_table =
        ((struct unary_expression *) (buff->parent))->sym_table;
      break;

    case NODE_POSTFIX_EXPRESSION:
      buff->sym_table =
        ((struct postfix_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->pf_kind == POSTFIX_PRIMARY && buff->pex != NULL)
    buff->pex->create_symtable (buff->pex);
  else
    switch (buff->pf_kind)
      {
      case POSTFIX_ARRAY:
        if (buff->pfex != NULL)
          buff->pfex->create_symtable (buff->pfex);
        if (buff->ex != NULL)
          buff->ex->create_symtable (buff->ex);
        break;

      case POSTFIX_FUNCTION:
        if (buff->pfex != NULL)
          buff->pfex->create_symtable (buff->pfex);
        if (buff->ael != NULL)
          buff->ael->create_symtable (buff->ael);
        break;

      case POSTFIX_FIELD1:
      case POSTFIX_FIELD2:
      case POSTFIX_INC:
      case POSTFIX_DEC:
        if (buff->pfex != NULL)
          buff->pfex->create_symtable (buff->pfex);
        break;

      case POSTFIX_COMP_LIT:
        if (buff->comp_lit.tn != NULL)
          buff->comp_lit.tn->create_symtable (buff->comp_lit.tn);
        if (buff->comp_lit.il != NULL)
          buff->comp_lit.il->create_symtable (buff->comp_lit.il);
        break;

      default:
        ;                       /* BUG! */
      }
}

static void
pe_create_symbol (struct postfix_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_POSTFIX_EXPRESSION);
  assert (buff->sym_table != NULL);

  switch (buff->pf_kind)
    {
    case POSTFIX_PRIMARY:
      buff->pex->create_symbol (buff->pex);
      break;

    case POSTFIX_ARRAY:
      buff->pfex->create_symbol (buff->pfex);
      /* TODO buff->ex->create_symbol (buff->ex); */
      break;

    case POSTFIX_FUNCTION:
      buff->pfex->create_symbol (buff->pfex);
      /* TODO if (buff->ael != NULL) buff->ael->create_symbol (buff->ael); */
      break;

    case POSTFIX_FIELD1:
    case POSTFIX_FIELD2:
      buff->pfex->create_symbol (buff->pfex);
      pe_create_symbol_field (buff);
      break;

    case POSTFIX_INC:
    case POSTFIX_DEC:
      buff->pfex->create_symbol (buff->pfex);
      break;

    case POSTFIX_COMP_LIT:
      /* TODO buff->comp_lit.tn->create_symbol (buff->comp_lit->tn); */
      /* TODO buff->comp_lit.il->create_symbol (buff->comp_lit->il); */
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
pe_create_symbol_field (struct postfix_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_POSTFIX_EXPRESSION);
  assert (buff->sym_table != NULL);
  assert (buff->pf_kind == POSTFIX_FIELD1 || buff->pf_kind == POSTFIX_FIELD2);

  /*
   * We need to look for the declaration of the
   * struct or union and look for its field.
   * But first we need to look for the type of the
   * postfix-expression before the . or -> operator.
   */

  /* TODO fucking difficult I'm afraid */
}
