#include <assert.h>
#include <stdlib.h>

#include "init_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct init_declarator *
init_declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct init_declarator *buff = calloc (1, sizeof (struct init_declarator));
  assert (buff);
  buff->kind = NODE_INIT_DECLARATOR;
  buff->dclr = ptr1;
  buff->itz = ptr2;
#if 0
  buff->dclr->parent_kind = buff->itz->parent_kind = NODE_INIT_DECLARATOR;
  buff->dclr->parent = buff->itz->parent = buff;
#endif

  return buff;
}

struct init_declarator *
init_declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct init_declarator *buff = calloc (1, sizeof (struct init_declarator));
  assert (buff);
  buff->kind = NODE_INIT_DECLARATOR;
  buff->dclr = ptr;
#if 0
  buff->dclr->parent_kind = NODE_INIT_DECLARATOR;
  buff->dclr->parent = buff;
#endif

  return buff;
}
