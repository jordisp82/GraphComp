#include <assert.h>
#include <stdlib.h>

#include "translation_unit.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct translation_unit *
translation_unit_1 (void *ptr)
{
  assert (ptr != NULL);

  struct translation_unit *buff =
    calloc (1, sizeof (struct translation_unit));
  assert (buff != NULL);
  buff->kind = NODE_TRANSLATION_UNIT;
  buff->first = calloc (1, sizeof (struct tu_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ed = ptr;
#if 0
  buff->first->ed->parent = buff;
  buff->first->ed->parent_kind = NODE_TRANSLATION_UNIT;
#endif

  return buff;
}

struct translation_unit *
translation_unit_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct translation_unit *buff = ptr1;
  struct external_declaration *ed = ptr2;

  buff->last->next = calloc (1, sizeof (struct tu_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ed = ed;
#if 0
  ed->parent = buff;
  ed->parent_kind = NODE_TRANSLATION_UNIT;
#endif

  return buff;
}