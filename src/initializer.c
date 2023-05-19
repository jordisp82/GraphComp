#include <assert.h>
#include <stdlib.h>

#include "initializer.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct initializer *
initializer_1 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_LIST;
  buff->il = ptr;
#if 0
  buff->il->parent_kind = NODE_INITIALIZER;
  buff->il->parent = buff;
#endif

  return buff;
}

struct initializer *
initializer_2 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_LIST;
  buff->il = ptr;
#if 0
  buff->il->parent_kind = NODE_INITIALIZER;
  buff->il->parent = buff;
#endif

  return buff;
}

struct initializer *
initializer_3 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_ASS_EXPR;
  buff->ae = ptr;
#if 0
  buff->ae->parent_kind = NODE_INITIALIZER;
  buff->ae->parent = buff;
#endif

  return buff;
}
