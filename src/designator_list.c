#include <assert.h>
#include <stdlib.h>

#include "designator_list.h"
#include "designator.h"
#include "designation.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct designator_list *
designator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct designator_list *buff = calloc (1, sizeof (struct designator_list));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR_LIST;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds = ptr;
  buff->first->ds->parent_kind = NODE_DESIGNATOR_LIST;
  buff->first->ds->parent = buff;

  return buff;
}

struct designator_list *
designator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct designator_list *buff = ptr1;
  struct designator *ds = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds = ds;
  ds->parent_kind = NODE_DESIGNATOR_LIST;
  ds->parent = buff;

  return buff;
}
