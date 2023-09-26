#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
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

static void local_dot_create (void *Node, void *F);
static void do_term (struct postfix_expression *node, FILE * f,
                     const char *token, int n_token);

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct postfix_expression *node = Node;
  assert (node->kind == NODE_POSTFIX_EXPRESSION);
  FILE *f = F;

  if (node->pf_kind == POSTFIX_PRIMARY)
    {
      assert (node->pex != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->pex);
      fprintf (f, "\t%lu [label=\"primary expression\"]\n",
               (unsigned long) node->pex);
      node->pex->dot_create (node->pex, f);
    }
  else if (node->pf_kind != POSTFIX_COMP_LIT)
    {
      assert (node->pfex != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->pfex);
      fprintf (f, "\t%lu [label=\"postfix expression\"]\n",
               (unsigned long) node->pfex);
      node->pfex->dot_create (node->pfex, f);

      switch (node->pf_kind)
        {
        case POSTFIX_ARRAY:
          do_term (node, f, "[", 0);
          assert (node->ex != NULL);
          fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                   (unsigned long) node->ex);
          fprintf (f, "\t%lu [label=\"expression\"]\n",
                   (unsigned long) node->ex);
          node->ex->dot_create (node->ex, f);
          do_term (node, f, "]", 1);
          break;

        case POSTFIX_FUNCTION:
          do_term (node, f, "(", 0);
          if (node->ael != NULL)
            {
              fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                       (unsigned long) node->ael);
              fprintf (f, "\t%lu [label=\"argument expression list\"]\n",
                       (unsigned long) node->ael);
              node->ael->dot_create (node->ael, f);
            }
          do_term (node, f, ")", 1);
          break;

        case POSTFIX_FIELD1:
          do_term (node, f, ".", 0);
          do_term (node, f, node->id, 1);
          break;

        case POSTFIX_FIELD2:
          do_term (node, f, "->", 0);
          do_term (node, f, node->id, 1);
          break;

        case POSTFIX_INC:
          do_term (node, f, "++", 0);
          break;

        case POSTFIX_DEC:
          do_term (node, f, "--", 0);
          break;

        default:;              /* BUG! */
        }
    }
  else
    {
      /* NOTE
       * compound literal, we discard any
       * trailing comma
       */
      do_term (node, f, "(", 0);
      assert (node->comp_lit.il != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->comp_lit.il);
      fprintf (f, "\t%lu [label=\"initializer list\"]\n",
               (unsigned long) node->comp_lit.il);
      node->comp_lit.il->dot_create (node->comp_lit.il, f);
      do_term (node, f, ")", 1);
      do_term (node, f, "{", 2);
      assert (node->comp_lit.tn != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->comp_lit.tn);
      fprintf (f, "\t%lu [label=\"typename\"]\n",
               (unsigned long) node->comp_lit.tn);
      node->comp_lit.tn->dot_create (node->comp_lit.tn, f);
      do_term (node, f, "}", 3);
    }
}

static void
do_term (struct postfix_expression *node, FILE * f, const char *token,
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
