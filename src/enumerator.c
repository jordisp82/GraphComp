#include <assert.h>
#include <stdlib.h>

#include "enumerator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct enumerator *
enumerator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct enumerator *buff = calloc (1, sizeof (struct enumerator));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR;
  buff->e_kind = ENUM_WITH_CONST_EXPR;
  buff->ec = ptr1;
  buff->expr = ptr2;
#if 0
  buff->ec->parent_kind = buff->expr->parent_kind = NODE_ENUMERATOR;
  buff->ec->parent = buff->expr->parent = buff;
#endif

  return buff;
}

struct enumerator *
enumerator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct enumerator *buff = calloc (1, sizeof (struct enumerator));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR;
  buff->e_kind = ENUM_NO_CONST_EXPR;
  buff->ec = ptr;
#if 0
  buff->ec->parent_kind = NODE_ENUMERATOR;
  buff->ec->parent = buff;
#endif

  return buff;
}
