#include <assert.h>
#include <stdlib.h>

#include "designation.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct designation *
designation_1 (void *ptr)
{
  assert (ptr != NULL);

  struct designation *buff = calloc (1, sizeof (struct designation));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATION;
  buff->dl = ptr;
#if 0
  buff->dl->parent_kind = NODE_DESIGNATION;
  buff->dl->parent = buff;
#endif

  return buff;
}
