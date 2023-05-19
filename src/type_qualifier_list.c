#include <assert.h>
#include <stdlib.h>

#include "type_qualifier_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct type_qualifier_list *
type_qualifier_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct type_qualifier_list *buff =
    calloc (1, sizeof (struct type_qualifier_list));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER_LIST;
  buff->first = calloc (1, sizeof (struct tql_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->tq = ptr;
#if 0
  buff->first->tq->parent_kind = NODE_TYPE_QUALIFIER_LIST;
  buff->first->tq->parent = buff;
#endif

  return buff;
}

struct type_qualifier_list *
type_qualifier_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_qualifier_list *buff = ptr1;
  struct type_qualifier *tq = ptr2;

  buff->last->next = calloc (1, sizeof (struct tql_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->tq = tq;
#if 0
  tq->parent_kind = NODE_TYPE_QUALIFIER_LIST;
  tq->parent = buff;
#endif

  return buff;
}
