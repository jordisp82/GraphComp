#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "argument_expression_list.h"
#include "assignment_expression.h"
#include "postfix_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct argument_expression_list *
argument_expression_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct argument_expression_list *buff =
    calloc (1, sizeof (struct argument_expression_list));
  assert (buff != NULL);
  buff->kind = NODE_ARGUMENT_EXPRESSION_LIST;
  buff->first = calloc (1, sizeof (struct ael_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ass = ptr;
  buff->first->ass->parent_kind = NODE_ARGUMENT_EXPRESSION_LIST;
  buff->first->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct argument_expression_list *
argument_expression_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct argument_expression_list *buff = ptr1;
  struct assignment_expression *ass = ptr2;

  buff->last->next = calloc (1, sizeof (struct ael_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ass = ass;
  ass->parent_kind = NODE_ARGUMENT_EXPRESSION_LIST;
  ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct argument_expression_list *node = Node;
  assert (node->kind == NODE_ARGUMENT_EXPRESSION_LIST);
  FILE *f = F;

  for (struct ael_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) ptr->ass);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) ptr->ass);
      ptr->ass->dot_create (ptr->ass, f);
    }
}
