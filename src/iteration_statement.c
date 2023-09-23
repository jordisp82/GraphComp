#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

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

  return buff;
}

