#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "alignment_specifier.h"
#include "type_name.h"
#include "constant_expression.h"
#include "declaration_specifiers.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct alignment_specifier *node, FILE * f,
                     const char *token, int n_token);

struct alignment_specifier *
alignment_specifier_1 (void *ptr)
{
  assert (ptr != NULL);

  struct alignment_specifier *buff =
    calloc (1, sizeof (struct alignment_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ALIGNMENT_SPECIFIER;
  buff->a_kind = ALIGN_TYPE_NAME;
  buff->tn = ptr;
  buff->tn->parent_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->tn->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct alignment_specifier *
alignment_specifier_2 (void *ptr)
{
  assert (ptr != NULL);

  struct alignment_specifier *buff =
    calloc (1, sizeof (struct alignment_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ALIGNMENT_SPECIFIER;
  buff->a_kind = ALIGN_CONST_EXPR;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->expr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct alignment_specifier *node = Node;
  assert (node->kind == NODE_ALIGNMENT_SPECIFIER);
  FILE *f = F;

  do_term (node, f, "_Alignas", 0);
  do_term (node, f, "(", 1);

  switch (node->a_kind)
    {
    case ALIGN_TYPE_NAME:
      fprintf (f, "\t%lu -> %lu\n", (unsigned long) node,
               (unsigned long) node->tn);
      fprintf (f, "\t%lu [label=\"typename\"]\n", (unsigned long) node->tn);
      node->tn->dot_create (node->tn, f);
      break;

    case ALIGN_CONST_EXPR:
      fprintf (f, "\t%lu -> %lu\n", (unsigned long) node,
               (unsigned long) node->expr);
      fprintf (f, "\t%lu [label=\"constant expression\"]\n",
               (unsigned long) node->expr);
      node->expr->dot_create (node->expr, f);
      break;

    default:;                  /* BUG! */
    }

  do_term (node, f, ")", 2);
}

static void
do_term (struct alignment_specifier *node, FILE * f, const char *token,
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
