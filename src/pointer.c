#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "pointer.h"
#include "type_qualifier_list.h"
#include "declarator.h"
#include "abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct pointer *
pointer_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_TQ_PTR;
  buff->tql = ptr1;
  buff->ptr = ptr2;
  buff->tql->parent_kind = buff->ptr->parent_kind = NODE_POINTER;
  buff->tql->parent = buff->ptr->parent = buff;

  return buff;
}

struct pointer *
pointer_2 (void *ptr)
{
  assert (ptr != NULL);

  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_TQ;
  buff->tql = ptr;
  buff->tql->parent_kind = NODE_POINTER;
  buff->tql->parent = buff;

  return buff;
}

struct pointer *
pointer_3 (void *ptr)
{
  assert (ptr != NULL);

  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_PTR;
  buff->ptr = ptr;
  buff->ptr->parent_kind = NODE_POINTER;
  buff->ptr->parent = buff;

  return buff;
}

struct pointer *
pointer_4 (void)
{
  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_EMPTY;

  return buff;
}
