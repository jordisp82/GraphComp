#include <assert.h>
#include <stdlib.h>

#include "struct_declarator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct struct_declarator_list *
struct_declarator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declarator_list *buff =
    calloc (1, sizeof (struct struct_declarator_list));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATOR_LIST;
  buff->first = calloc (1, sizeof (struct sdl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->sd = ptr;
#if 0
  buff->first->sd->parent_kind = NODE_STRUCT_DECLARATOR_LIST;
  buff->first->sd->parent = buff;
#endif

  return buff;
}

struct struct_declarator_list *
struct_declarator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declarator_list *buff = ptr1;
  struct struct_declarator *d = ptr2;

  buff->last->next = calloc (1, sizeof (struct sdl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->sd = d;
#if 0
  d->parent_kind = NODE_STRUCT_DECLARATOR_LIST;
  d->parent = buff;
#endif

  return buff;
}
