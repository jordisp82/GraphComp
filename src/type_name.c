#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_name.h"
#include "specifier_qualifier_list.h"
#include "abstract_declarator.h"
#include "postfix_expression.h"
#include "unary_expression.h"
#include "cast_expression.h"
#include "atomic_type_specifier.h"
#include "alignment_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct type_name *
type_name_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_name *buff = calloc (1, sizeof (struct type_name));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_NAME;
  buff->sql = ptr1;
  buff->adlr = ptr2;
  buff->sql->parent_kind = buff->adlr->parent_kind = NODE_TYPE_NAME;
  buff->sql->parent = buff->adlr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_name *
type_name_2 (void *ptr)
{
  assert (ptr != NULL);

  struct type_name *buff = calloc (1, sizeof (struct type_name));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_NAME;
  buff->sql = ptr;
  buff->sql->parent_kind = NODE_TYPE_NAME;
  buff->sql->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct type_name *node = Node;
  assert (node->kind == NODE_TYPE_NAME);
  FILE *f = F;

  if (node->sql != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sql);
      fprintf (f, "\t%lu [label=\"specifier qualifier list\"]\n",
               (unsigned long) node->sql);
      node->sql->dot_create (node->sql, f);
    }
  if (node->adlr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->adlr);
      fprintf (f, "\t%lu [label=\"abstract declarator\"]\n",
               (unsigned long) node->adlr);
      node->adlr->dot_create (node->adlr, f);
    }
}
