#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enumerator.h"
#include "enumeration_constant.h"
#include "constant_expression.h"
#include "enumerator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct enumerator *node, FILE * f, const char *token,
                     int n_token);

struct enumerator *
enumerator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct enumerator *buff = calloc (1, sizeof (struct enumerator));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR;
  buff->e_kind = ENUM_WITH_CONST_EXPR;
  buff->ec = ptr1;
  buff->expr = ptr2;
  buff->ec->parent_kind = buff->expr->parent_kind = NODE_ENUMERATOR;
  buff->ec->parent = buff->expr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct enumerator *
enumerator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct enumerator *buff = calloc (1, sizeof (struct enumerator));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR;
  buff->e_kind = ENUM_NO_CONST_EXPR;
  buff->ec = ptr;
  buff->ec->parent_kind = NODE_ENUMERATOR;
  buff->ec->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct enumerator *node = Node;
  assert (node->kind == NODE_ENUMERATOR);
  FILE *f = F;

  assert (node->ec != NULL);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->ec);
  fprintf (f, "\t%lu [label=\"enumeration constant\"]\n",
           (unsigned long) node->ec);
  node->ec->dot_create (node->ec, f);
  if (node->expr != NULL)
    {
      do_term (node, f, "=", 0);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->expr);
      fprintf (f, "\t%lu [label=\"constant expression\"]\n",
               (unsigned long) node->expr);
      node->expr->dot_create (node->expr, f);
    }
}

static void
do_term (struct enumerator *node, FILE * f, const char *token, int n_token)
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
