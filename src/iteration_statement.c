#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "iteration_statement.h"
#include "expression.h"
#include "statement.h"
#include "expression_statement.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_child_1 (struct iteration_statement *node, FILE * f);
static void do_child_2 (struct iteration_statement *node, FILE * f);
static void do_child_3 (struct iteration_statement *node, FILE * f);
static void do_child_4 (struct iteration_statement *node, FILE * f);
static void do_child_5 (struct iteration_statement *node, FILE * f);
static void do_child_67 (struct iteration_statement *node, FILE * f);
static void do_term (struct iteration_statement *node, FILE * f,
                     const char *token, int n_token);

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct iteration_statement *node = Node;
  assert (node->kind == NODE_ITERATION_STATEMENT);
  FILE *f = F;

  do_child_1 (node, f);
  do_child_2 (node, f);
  do_child_3 (node, f);
  do_child_4 (node, f);
  do_child_5 (node, f);
  if (node->is_kind != IS_WHILE)
    do_child_67 (node, f);
}

static void
do_child_1 (struct iteration_statement *node, FILE * f)
{
  assert (node != NULL);
  assert (f != NULL);

  switch (node->is_kind)
    {
    case IS_WHILE:
      do_term (node, f, "while", 0);
      break;

    case IS_DO:
      do_term (node, f, "do", 0);
      break;

    case IS_FOR_ES_ES:
    case IS_FOR_ES_ES_EX:
    case IS_FOR_DECL_ES:
    case IS_FOR_DECL_ES_EX:
      do_term (node, f, "for", 0);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_child_2 (struct iteration_statement *node, FILE * f)
{
  assert (node != NULL);
  assert (f != NULL);

  switch (node->is_kind)
    {
    case IS_DO:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_do.st);
      fprintf (f, "\t%lu [label=\"statement\"]\n",
               (unsigned long) node->is_do.st);
      node->is_do.st->dot_create (node->is_do.st, f);
      break;

    case IS_WHILE:
    case IS_FOR_ES_ES:
    case IS_FOR_ES_ES_EX:
    case IS_FOR_DECL_ES:
    case IS_FOR_DECL_ES_EX:
      do_term (node, f, "(", 1);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_child_3 (struct iteration_statement *node, FILE * f)
{
  assert (node != NULL);
  assert (f != NULL);

  switch (node->is_kind)
    {
    case IS_WHILE:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_while.ex);
      fprintf (f, "\t%lu [label=\"expression\"]\n",
               (unsigned long) node->is_while.ex);
      node->is_while.ex->dot_create (node->is_while.ex, f);
      break;

    case IS_DO:
      do_term (node, f, "while", 2);
      break;

    case IS_FOR_ES_ES:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_es_es.es1);
      fprintf (f, "\t%lu [label=\"expression statement\"]\n",
               (unsigned long) node->is_for_es_es.es1);
      node->is_for_es_es.es1->dot_create (node->is_for_es_es.es1, f);
      break;

    case IS_FOR_ES_ES_EX:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_es_es_ex.es1);
      fprintf (f, "\t%lu [label=\"expression statement\"]\n",
               (unsigned long) node->is_for_es_es_ex.es1);
      node->is_for_es_es_ex.es1->dot_create (node->is_for_es_es_ex.es1, f);
      break;

    case IS_FOR_DECL_ES:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_decl_es.dl);
      fprintf (f, "\t%lu [label=\"declaration\"]\n",
               (unsigned long) node->is_for_decl_es.dl);
      node->is_for_decl_es.dl->dot_create (node->is_for_decl_es.dl, f);
      break;

    case IS_FOR_DECL_ES_EX:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_decl_es_ex.dl);
      fprintf (f, "\t%lu [label=\"declaration\"]\n",
               (unsigned long) node->is_for_decl_es_ex.dl);
      node->is_for_decl_es_ex.dl->dot_create (node->is_for_decl_es_ex.dl, f);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_child_4 (struct iteration_statement *node, FILE * f)
{
  assert (node != NULL);
  assert (f != NULL);

  switch (node->is_kind)
    {
    case IS_WHILE:
      do_term (node, f, ")", 3);
      break;

    case IS_DO:
      do_term (node, f, "(", 3);
      break;

    case IS_FOR_ES_ES:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_es_es.es2);
      fprintf (f, "\t%lu [label=\"expression statement\"]\n",
               (unsigned long) node->is_for_es_es.es2);
      node->is_for_es_es.es2->dot_create (node->is_for_es_es.es2, f);
      break;

    case IS_FOR_ES_ES_EX:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_es_es_ex.es2);
      fprintf (f, "\t%lu [label=\"expression statement\"]\n",
               (unsigned long) node->is_for_es_es_ex.es2);
      node->is_for_es_es_ex.es2->dot_create (node->is_for_es_es_ex.es2, f);
      break;

    case IS_FOR_DECL_ES:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_decl_es.es);
      fprintf (f, "\t%lu [label=\"expression statement\"]\n",
               (unsigned long) node->is_for_decl_es.es);
      node->is_for_decl_es.es->dot_create (node->is_for_decl_es.es, f);
      break;

    case IS_FOR_DECL_ES_EX:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_decl_es_ex.es);
      fprintf (f, "\t%lu [label=\"expression statement\"]\n",
               (unsigned long) node->is_for_decl_es_ex.es);
      node->is_for_decl_es_ex.es->dot_create (node->is_for_decl_es_ex.es, f);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_child_5 (struct iteration_statement *node, FILE * f)
{
  assert (node != NULL);
  assert (f != NULL);

  switch (node->is_kind)
    {
    case IS_WHILE:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_while.st);
      fprintf (f, "\t%lu [label=\"statement\"]\n",
               (unsigned long) node->is_while.st);
      node->is_while.st->dot_create (node->is_while.st, f);
      break;

    case IS_DO:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_do.ex);
      fprintf (f, "\t%lu [label=\"expression\"]\n",
               (unsigned long) node->is_do.ex);
      node->is_do.ex->dot_create (node->is_do.ex, f);
      break;

    case IS_FOR_ES_ES:
    case IS_FOR_DECL_ES:
      do_term (node, f, ")", 4);
      break;

    case IS_FOR_ES_ES_EX:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_es_es_ex.ex);
      fprintf (f, "\t%lu [label=\"expression\"]\n",
               (unsigned long) node->is_for_es_es_ex.ex);
      node->is_for_es_es_ex.ex->dot_create (node->is_for_es_es_ex.ex, f);
      break;

    case IS_FOR_DECL_ES_EX:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_decl_es_ex.ex);
      fprintf (f, "\t%lu [label=\"expression\"]\n",
               (unsigned long) node->is_for_decl_es_ex.ex);
      node->is_for_decl_es_ex.ex->dot_create (node->is_for_decl_es_ex.ex, f);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_child_67 (struct iteration_statement *node, FILE * f)
{
  assert (node != NULL);
  assert (f != NULL);

  switch (node->is_kind)
    {
    case IS_DO:
      do_term (node, f, ")", 5);
      do_term (node, f, ";", 6);
      break;

    case IS_FOR_ES_ES:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_es_es.st);
      fprintf (f, "\t%lu [label=\"statement\"]\n",
               (unsigned long) node->is_for_es_es.st);
      node->is_for_es_es.st->dot_create (node->is_for_es_es.st, f);
      break;

    case IS_FOR_DECL_ES:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_decl_es.st);
      fprintf (f, "\t%lu [label=\"statement\"]\n",
               (unsigned long) node->is_for_decl_es.st);
      node->is_for_decl_es.st->dot_create (node->is_for_decl_es.st, f);
      break;

    case IS_FOR_ES_ES_EX:
      do_term (node, f, ")", 5);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_es_es_ex.st);
      fprintf (f, "\t%lu [label=\"statement\"]\n",
               (unsigned long) node->is_for_es_es_ex.st);
      node->is_for_es_es_ex.st->dot_create (node->is_for_es_es_ex.st, f);
      break;

    case IS_FOR_DECL_ES_EX:
      do_term (node, f, ")", 5);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->is_for_decl_es_ex.st);
      fprintf (f, "\t%lu [label=\"statement\"]\n",
               (unsigned long) node->is_for_decl_es_ex.st);
      node->is_for_decl_es_ex.st->dot_create (node->is_for_decl_es_ex.st, f);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct iteration_statement *node, FILE * f, const char *token,
         int n_token)
{
  assert (node != NULL);
  assert (f != NULL);
  assert (token != NULL);
  assert (n_token >= 0);

  fprintf (f, "\t%lu -> %lu%d;\n", (unsigned long) node,
           (unsigned long) node, n_token);
  fprintf (f, "\t%lu%d [label=\"%s\",shape=box,fontname=Courier]\n",
           (unsigned long) node, n_token, token);
}
