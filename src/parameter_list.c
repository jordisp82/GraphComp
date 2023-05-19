#include <assert.h>
#include <stdlib.h>

#include "parameter_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct parameter_list *
parameter_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_list *buff = calloc (1, sizeof (struct parameter_list));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_LIST;
  buff->first = calloc (1, sizeof (struct pl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->pd = ptr;
#if 0
  buff->first->pd->parent_kind = NODE_PARAMETER_LIST;
  buff->first->pd->parent = buff;
#endif

  return buff;
}

struct parameter_list *
parameter_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct parameter_list *buff = ptr1;
  struct parameter_declaration *pd = ptr2;

  buff->last->next = calloc (1, sizeof (struct pl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->pd = pd;
#if 0
  pd->parent_kind = NODE_PARAMETER_LIST;
  pd->parent = buff;
#endif

  return buff;
}
