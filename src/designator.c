#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "designator.h"
#include "constant_expression.h"

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
  buff->ex->parent_kind = NODE_DESIGNATOR;
  buff->ex->parent = buff;

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

void
set_designator_scope (struct designator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATOR);

  switch (buff->parent_kind)
    {
    case NODE_DESIGNATOR_LIST:
      break;

    default:
      ;                         /* BUG! */
    }
}
