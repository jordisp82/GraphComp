#include <assert.h>
#include <stdlib.h>

#include "declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct declarator *
declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declarator *buff = calloc (1, sizeof (struct declarator));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATOR;
  buff->dclr_kind = DCLR_WITH_POINTER;
  buff->ptr = ptr1;
  buff->ddclr = ptr2;
#if 0
  buff->ptr->parent_kind = buff->ddclr->parent_kind = NODE_DECLARATOR;
  buff->ptr->parent = buff->ddclr->parent = buff;
#endif

  return buff;
}

struct declarator *
declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct declarator *buff = calloc (1, sizeof (struct declarator));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATOR;
  buff->dclr_kind = DCLR_NO_POINTER;
  buff->ddclr = ptr;
#if 0
  buff->ddclr->parent_kind = NODE_DECLARATOR;
  buff->ddclr->parent = buff;
#endif

  return buff;
}
