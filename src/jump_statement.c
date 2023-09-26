#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jump_statement.h"
#include "expression.h"
#include "statement.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct jump_statement *node, FILE * f,
                     const char *token, int n_token);

struct jump_statement *
jump_statement_1 (const char *str)
{
  assert (str != NULL);

  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_GOTO;
  buff->id = strdup (str);
  assert (buff->id != NULL);

  buff->dot_create = local_dot_create;

  return buff;
}

struct jump_statement *
jump_statement_2 (void)
{
  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_CONTINUE;

  buff->dot_create = local_dot_create;

  return buff;
}

struct jump_statement *
jump_statement_3 (void)
{
  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_BREAK;

  buff->dot_create = local_dot_create;

  return buff;
}

struct jump_statement *
jump_statement_4 (void)
{
  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_RETURN_VOID;

  buff->dot_create = local_dot_create;

  return buff;
}

struct jump_statement *
jump_statement_5 (void *ptr)
{
  assert (ptr != NULL);

  struct jump_statement *buff = calloc (1, sizeof (struct jump_statement));
  assert (buff != NULL);
  buff->kind = NODE_JUMP_STATEMENT;
  buff->js_kind = JS_RETURN_EXP;
  buff->exp = ptr;
  buff->exp->parent_kind = NODE_JUMP_STATEMENT;
  buff->exp->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct jump_statement *node = Node;
  assert (node->kind == NODE_JUMP_STATEMENT);
  FILE *f = F;

  switch (node->js_kind)
    {
    case JS_GOTO:
      do_term (node, f, "goto", 0);
      do_term (node, f, node->id, 1);
      do_term (node, f, ";", 2);
      break;

    case JS_CONTINUE:
      do_term (node, f, "continue", 0);
      do_term (node, f, ";", 1);
      break;

    case JS_BREAK:
      do_term (node, f, "break", 0);
      do_term (node, f, ";", 1);
      break;

    case JS_RETURN_VOID:
      do_term (node, f, "return", 0);
      do_term (node, f, ";", 1);
      break;

    case JS_RETURN_EXP:
      do_term (node, f, "return", 0);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->exp);
      fprintf (f, "\t%lu [label=\"expression\"]\n",
               (unsigned long) node->exp);
      do_term (node, f, ";", 1);
      node->exp->dot_create (node->exp, f);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct jump_statement *node, FILE * f, const char *token,
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
