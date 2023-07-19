#include <assert.h>
#include <stdlib.h>

#include "iteration_statement.h"
#include "expression.h"
#include "statement.h"
#include "expression_statement.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void is_create_symtable (struct iteration_statement *buff);
static void is_create_symbol (struct iteration_statement *buff);

struct iteration_statement *
iteration_statement_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct iteration_statement *buff =
    calloc (1, sizeof (struct iteration_statement));
  assert (buff != NULL);
  buff->kind = NODE_ITERATION_STATEMENT;
  buff->is_kind = IS_WHILE;
  buff->is_while.ex = ptr1;
  buff->is_while.st = ptr2;
  buff->is_while.ex->parent_kind = buff->is_while.st->parent_kind =
    NODE_ITERATION_STATEMENT;
  buff->is_while.ex->parent = buff->is_while.st->parent = buff;
  buff->create_symtable = is_create_symtable;
  buff->create_symbol = is_create_symbol;

  return buff;
}

struct iteration_statement *
iteration_statement_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct iteration_statement *buff =
    calloc (1, sizeof (struct iteration_statement));
  assert (buff != NULL);
  buff->kind = NODE_ITERATION_STATEMENT;
  buff->is_kind = IS_DO;
  buff->is_do.st = ptr1;
  buff->is_do.ex = ptr2;
  buff->is_do.st->parent_kind = buff->is_do.ex->parent_kind =
    NODE_ITERATION_STATEMENT;
  buff->is_do.st->parent = buff->is_do.ex->parent = buff;
  buff->create_symtable = is_create_symtable;
  buff->create_symbol = is_create_symbol;

  return buff;
}

struct iteration_statement *
iteration_statement_3 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct iteration_statement *buff =
    calloc (1, sizeof (struct iteration_statement));
  assert (buff != NULL);
  buff->kind = NODE_ITERATION_STATEMENT;
  buff->is_kind = IS_FOR_ES_ES;
  buff->is_for_es_es.es1 = ptr1;
  buff->is_for_es_es.es2 = ptr2;
  buff->is_for_es_es.st = ptr3;
  buff->is_for_es_es.es1->parent_kind = buff->is_for_es_es.es2->parent_kind =
    buff->is_for_es_es.st->parent_kind = NODE_ITERATION_STATEMENT;
  buff->is_for_es_es.es1->parent = buff->is_for_es_es.es2->parent =
    buff->is_for_es_es.st->parent = buff;
  buff->create_symtable = is_create_symtable;
  buff->create_symbol = is_create_symbol;

  return buff;
}

struct iteration_statement *
iteration_statement_4 (void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);
  assert (ptr4 != NULL);

  struct iteration_statement *buff =
    calloc (1, sizeof (struct iteration_statement));
  assert (buff != NULL);
  buff->kind = NODE_ITERATION_STATEMENT;
  buff->is_kind = IS_FOR_ES_ES_EX;
  buff->is_for_es_es_ex.es1 = ptr1;
  buff->is_for_es_es_ex.es2 = ptr2;
  buff->is_for_es_es_ex.ex = ptr3;
  buff->is_for_es_es_ex.st = ptr4;
  buff->is_for_es_es_ex.es1->parent_kind =
    buff->is_for_es_es_ex.es2->parent_kind =
    buff->is_for_es_es_ex.ex->parent_kind =
    buff->is_for_es_es_ex.st->parent_kind = NODE_ITERATION_STATEMENT;
  buff->is_for_es_es_ex.es1->parent = buff->is_for_es_es_ex.es2->parent =
    buff->is_for_es_es_ex.ex->parent = buff->is_for_es_es_ex.st->parent =
    buff;
  buff->create_symtable = is_create_symtable;
  buff->create_symbol = is_create_symbol;

  return buff;
}

struct iteration_statement *
iteration_statement_5 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct iteration_statement *buff =
    calloc (1, sizeof (struct iteration_statement));
  assert (buff != NULL);
  buff->kind = NODE_ITERATION_STATEMENT;
  buff->is_kind = IS_FOR_DECL_ES;
  buff->is_for_decl_es.dl = ptr1;
  buff->is_for_decl_es.es = ptr2;
  buff->is_for_decl_es.st = ptr3;
  buff->is_for_decl_es.dl->parent_kind =
    buff->is_for_decl_es.es->parent_kind =
    buff->is_for_decl_es.st->parent_kind = NODE_ITERATION_STATEMENT;
  buff->is_for_decl_es.dl->parent = buff->is_for_decl_es.es->parent =
    buff->is_for_decl_es.st->parent = buff;
  buff->create_symtable = is_create_symtable;
  buff->create_symbol = is_create_symbol;

  return buff;
}

struct iteration_statement *
iteration_statement_6 (void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);
  assert (ptr4 != NULL);

  struct iteration_statement *buff =
    calloc (1, sizeof (struct iteration_statement));
  assert (buff != NULL);
  buff->kind = NODE_ITERATION_STATEMENT;
  buff->is_kind = IS_FOR_DECL_ES_EX;
  buff->is_for_decl_es_ex.dl = ptr1;
  buff->is_for_decl_es_ex.es = ptr2;
  buff->is_for_decl_es_ex.ex = ptr3;
  buff->is_for_decl_es_ex.st = ptr4;
  buff->is_for_decl_es_ex.dl->parent_kind =
    buff->is_for_decl_es_ex.es->parent_kind =
    buff->is_for_decl_es_ex.ex->parent_kind =
    buff->is_for_decl_es_ex.st->parent_kind = NODE_ITERATION_STATEMENT;
  buff->is_for_decl_es_ex.dl->parent = buff->is_for_decl_es_ex.es->parent =
    buff->is_for_decl_es_ex.ex->parent = buff->is_for_decl_es_ex.st->parent =
    buff;
  buff->create_symtable = is_create_symtable;
  buff->create_symbol = is_create_symbol;

  return buff;
}

static void
is_create_symtable (struct iteration_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ITERATION_STATEMENT);

  buff->sym_table = ((struct statement *) (buff->parent))->sym_table;
  switch (buff->is_kind)
    {
    case IS_WHILE:
      buff->is_while.st->create_symtable (buff->is_while.st);
      buff->is_while.ex->create_symtable (buff->is_while.ex);
      break;

    case IS_DO:
      buff->is_do.st->create_symtable (buff->is_do.st);
      buff->is_do.ex->create_symtable (buff->is_do.ex);
      break;

    case IS_FOR_ES_ES:
      buff->is_for_es_es.st->create_symtable (buff->is_for_es_es.st);
      buff->is_for_es_es.es1->create_symtable (buff->is_for_es_es.es1);
      buff->is_for_es_es.es2->create_symtable (buff->is_for_es_es.es2);
      break;

    case IS_FOR_ES_ES_EX:
      buff->is_for_es_es_ex.st->create_symtable (buff->is_for_es_es_ex.st);
      buff->is_for_es_es_ex.ex->create_symtable (buff->is_for_es_es_ex.ex);
      buff->is_for_es_es_ex.es1->create_symtable (buff->is_for_es_es_ex.es1);
      buff->is_for_es_es_ex.es2->create_symtable (buff->is_for_es_es_ex.es2);
      break;

    case IS_FOR_DECL_ES:
      buff->is_for_decl_es.st->create_symtable (buff->is_for_decl_es.st);
      buff->is_for_decl_es.dl->create_symtable (buff->is_for_decl_es.dl);
      buff->is_for_decl_es.es->create_symtable (buff->is_for_decl_es.es);
      break;

    case IS_FOR_DECL_ES_EX:
      buff->is_for_decl_es_ex.st->create_symtable (buff->
                                                   is_for_decl_es_ex.st);
      buff->is_for_decl_es_ex.dl->create_symtable (buff->
                                                   is_for_decl_es_ex.dl);
      buff->is_for_decl_es_ex.ex->create_symtable (buff->
                                                   is_for_decl_es_ex.ex);
      buff->is_for_decl_es_ex.es->create_symtable (buff->
                                                   is_for_decl_es_ex.es);
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
is_create_symbol (struct iteration_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ITERATION_STATEMENT);
  assert (buff->sym_table != NULL);

  switch (buff->is_kind)
    {
    case IS_WHILE:
      buff->is_while.st->create_symbol (buff->is_while.st);
      buff->is_while.ex->create_symbol (buff->is_while.ex);
      break;

    case IS_DO:
      buff->is_do.st->create_symbol (buff->is_do.st);
      buff->is_do.ex->create_symbol (buff->is_do.ex);
      break;

    case IS_FOR_ES_ES:
      buff->is_for_es_es.st->create_symbol (buff->is_for_es_es.st);
      buff->is_for_es_es.es1->create_symbol (buff->is_for_es_es.es1);
      buff->is_for_es_es.es2->create_symbol (buff->is_for_es_es.es2);
      break;

    case IS_FOR_ES_ES_EX:
      buff->is_for_es_es_ex.st->create_symbol (buff->is_for_es_es_ex.st);
      buff->is_for_es_es_ex.ex->create_symbol (buff->is_for_es_es_ex.ex);
      buff->is_for_es_es_ex.es1->create_symbol (buff->is_for_es_es_ex.es1);
      buff->is_for_es_es_ex.es2->create_symbol (buff->is_for_es_es_ex.es2);
      break;

    case IS_FOR_DECL_ES:
      buff->is_for_decl_es.st->create_symbol (buff->is_for_decl_es.st);
      buff->is_for_decl_es.dl->create_symbol (buff->is_for_decl_es.dl);
      buff->is_for_decl_es.es->create_symbol (buff->is_for_decl_es.es);
      break;

    case IS_FOR_DECL_ES_EX:
      buff->is_for_decl_es_ex.st->create_symbol (buff->is_for_decl_es_ex.st);
      buff->is_for_decl_es_ex.dl->create_symbol (buff->is_for_decl_es_ex.dl);
      buff->is_for_decl_es_ex.ex->create_symbol (buff->is_for_decl_es_ex.ex);
      buff->is_for_decl_es_ex.es->create_symbol (buff->is_for_decl_es_ex.es);
      break;

    default:
      ;                         /* BUG! */
    }
}
