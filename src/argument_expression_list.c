#include <assert.h>
#include <stdlib.h>

#include "argument_expression_list.h"
#include "assignment_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

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

  return buff;
}
