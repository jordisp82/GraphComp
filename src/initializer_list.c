#include <assert.h>
#include <stdlib.h>

#include "initializer_list.h"
#include "designation.h"
#include "initializer.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct initializer_list *
initializer_list_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct initializer_list *buff =
    calloc (1, sizeof (struct initializer_list));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER_LIST;
  buff->first = calloc (1, sizeof (struct il_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->il_kind = IL_D_I;
  buff->first->d = ptr1;
  buff->first->i = ptr2;
  buff->first->d->parent_kind = buff->first->i->parent_kind =
    NODE_INITIALIZER_LIST;
  buff->first->d->parent = buff->first->i->parent = buff;

  return buff;
}

struct initializer_list *
initializer_list_2 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer_list *buff =
    calloc (1, sizeof (struct initializer_list));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER_LIST;
  buff->first = calloc (1, sizeof (struct il_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->il_kind = IL_I;
  buff->first->i = ptr;
  buff->first->i->parent_kind = NODE_INITIALIZER_LIST;
  buff->first->i->parent = buff;

  return buff;
}

struct initializer_list *
initializer_list_3 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct initializer_list *buff = ptr1;
  struct designation *d = ptr2;
  struct initializer *i = ptr3;

  buff->last->next = calloc (1, sizeof (struct il_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->il_kind = IL_D_I;
  buff->last->d = d;
  buff->last->i = i;
  d->parent_kind = i->parent_kind = NODE_INITIALIZER_LIST;
  d->parent = i->parent = buff;

  return buff;
}

struct initializer_list *
initializer_list_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct initializer_list *buff = ptr1;
  struct initializer *i = ptr2;

  buff->last->next = calloc (1, sizeof (struct il_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->il_kind = IL_I;
  buff->last->i = i;
  i->parent_kind = NODE_INITIALIZER_LIST;
  i->parent = buff;

  return buff;
}
