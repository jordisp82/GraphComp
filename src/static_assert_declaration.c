#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "static_assert_declaration.h"
#include "constant_expression.h"
#include "declaration.h"
#include "struct_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct static_assert_declaration *node, FILE * f,
                     const char *token, int n_token);

struct static_assert_declaration *
static_assert_declaration_1 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct static_assert_declaration *buff =
    calloc (1, sizeof (struct static_assert_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STATIC_ASSERT_DECLARATION;
  buff->expr = ptr1;
  buff->str = strdup (str);
  assert (buff->str != NULL);
  buff->expr->parent_kind = NODE_STATIC_ASSERT_DECLARATION;
  buff->expr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct static_assert_declaration *node = Node;
  assert (node->kind == NODE_STATIC_ASSERT_DECLARATION);
  FILE *f = F;

  do_term (node, f, "_Static_assert", 0);
  do_term (node, f, "(", 1);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->expr);
  fprintf (f, "\t%lu [label=\"constant expression\"]\n",
           (unsigned long) node->expr);
  node->expr->dot_create (node->expr, f);
  do_term (node, f, node->str, 2);
  do_term (node, f, ")", 3);
  do_term (node, f, ";", 4);
}

static void
do_term (struct static_assert_declaration *node, FILE * f, const char *token,
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
