#include <assert.h>
#include <stdlib.h>

#include "init_declarator_list.h"
#include "init_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct init_declarator_list *
init_declarator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct init_declarator_list *buff =
    calloc (1, sizeof (struct init_declarator_list));
  assert (buff != NULL);
  buff->kind = NODE_INIT_DECLARATOR_LIST;
  buff->first = calloc (1, sizeof (struct idl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->id = ptr;
  buff->first->id->parent_kind = NODE_INIT_DECLARATOR_LIST;
  buff->first->id->parent = buff;

  return buff;
}

struct init_declarator_list *
init_declarator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct init_declarator_list *buff = ptr1;
  struct init_declarator *id = ptr2;

  buff->last->next = calloc (1, sizeof (struct idl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->id = id;
  id->parent_kind = NODE_INIT_DECLARATOR_LIST;
  id->parent = buff;

  return buff;
}
