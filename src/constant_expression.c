#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "constant_expression.h"
#include "conditional_expression.h"
#include "labeled_statement.h"
#include "static_assert_declaration.h"
#include "alignment_specifier.h"
#include "struct_declarator.h"
#include "enumerator.h"
#include "designator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct constant_expression *
constant_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct constant_expression *buff =
    calloc (1, sizeof (struct constant_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT_EXPRESSION;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_CONSTANT_EXPRESSION;
  buff->expr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct constant_expression *node = Node;
  assert (node->kind == NODE_CONSTANT_EXPRESSION);
  FILE *f = F;

  assert (node->expr != NULL);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->expr);
  fprintf (f, "\t%lu [label=\"conditional expression\"]\n",
           (unsigned long) node->expr);
  node->expr->dot_create (node->expr, f);
}
