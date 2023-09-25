#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "primary_expression.h"
#include "constant.h"
#include "string_symbol.h"
#include "expression.h"
#include "postfix_expression.h"
#include "translation_unit.h"
#include "compound_statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct primary_expression *node, FILE * f,
                     const char *token, int n_token);

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct primary_expression *node = Node;
  assert (node->kind == NODE_PRIMARY_EXPRESSION);
  FILE *f = F;

  switch (node->priex_kind)
    {
    case PRIEX_IDENT:
      do_term (node, f, node->id, 0);
      break;

    case PRIEX_CONST:
      assert (node->c != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->c);
      fprintf (f, "\t%lu [label=\"constant\"]\n", (unsigned long) node->c);
      node->c->dot_create (node->c, f);
      break;

    case PRIEX_STRING:
      /* TODO */
      break;

    case PRIEX_EX:
      assert (node->e != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->e);
      fprintf (f, "\t%lu [label=\"expression\"]\n", (unsigned long) node->e);
      node->e->dot_create (node->e, f);
      break;

    case PRIEX_GS:
      /* NOTE fuck generic selection */
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct primary_expression *node, FILE * f, const char *token,
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
