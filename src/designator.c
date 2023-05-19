#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "designator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct designator *
designator_1 (void *ptr)
{
  assert (ptr != NULL);

  struct designator *buff = calloc (1, sizeof (struct designator));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR;
  buff->d_kind = DESIGNATOR_ARRAY;
  buff->ex = ptr;
#if 0
  buff->ex->parent_kind = NODE_DESIGNATOR;
  buff->ex->parent = buff;
#endif

  return buff;
}

struct designator *
designator_2 (const char *str)
{
  assert (str != NULL);

  struct designator *buff = calloc (1, sizeof (struct designator));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR;
  buff->d_kind = DESIGNATOR_FIELD;
  buff->str = strdup (str);
  assert (buff->str != NULL);

  return buff;
}
