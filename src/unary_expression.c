#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
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

static void local_dot_create (void *Node, void *F);
static void do_term (struct unary_expression *node, FILE * f,
                     const char *token, int n_token);

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct unary_expression *node = Node;
  assert (node->kind == NODE_UNARY_EXPRESSION);
  FILE *f = F;

  switch (node->unary_kind)
    {
    case UNARY_POSTFIX:
      assert (node->pex != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->pex);
      fprintf (f, "\t%lu [label=\"postfix expression\"]\n",
               (unsigned long) node->pex);
      node->pex->dot_create (node->pex, f);
      break;

    case UNARY_INC:
      assert (node->unex != NULL);
      do_term (node, f, "++", 0);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->unex);
      fprintf (f, "\t%lu [label=\"unary expression\"]\n",
               (unsigned long) node->unex);
      node->unex->dot_create (node->unex, f);
      break;

    case UNARY_DEC:
      assert (node->unex != NULL);
      do_term (node, f, "--", 0);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->unex);
      fprintf (f, "\t%lu [label=\"unary expression\"]\n",
               (unsigned long) node->unex);
      node->unex->dot_create (node->unex, f);
      break;

    case UNARY_OP:
      assert (node->unop != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->unop);
      fprintf (f, "\t%lu [label=\"unary operator\"]\n",
               (unsigned long) node->unop);
      node->unop->dot_create (node->unop, f);
      assert (node->cex != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->cex);
      fprintf (f, "\t%lu [label=\"cast expression\"]\n",
               (unsigned long) node->cex);
      node->cex->dot_create (node->cex, f);
      break;

    case UNARY_SIZEOF1:
      assert (node->unex != NULL);
      do_term (node, f, "sizeof", 0);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->unex);
      fprintf (f, "\t%lu [label=\"unary expression\"]\n",
               (unsigned long) node->unex);
      node->unex->dot_create (node->unex, f);
      break;

    case UNARY_SIZEOF2:
      assert (node->tn != NULL);
      do_term (node, f, "sizeof", 0);
      do_term (node, f, "(", 1);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->tn);
      fprintf (f, "\t%lu [label=\"typename\"]\n", (unsigned long) node->tn);
      node->tn->dot_create (node->tn, f);
      do_term (node, f, ")", 2);
      break;

    case UNARY_ALIGNOF:
      assert (node->tn != NULL);
      do_term (node, f, "_Alignof", 0);
      do_term (node, f, "(", 1);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->tn);
      fprintf (f, "\t%lu [label=\"typename\"]\n", (unsigned long) node->tn);
      node->tn->dot_create (node->tn, f);
      do_term (node, f, ")", 2);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct unary_expression *node, FILE * f, const char *token,
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
