#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "parameter_type_list.h"
#include "parameter_list.h"
#include "direct_declarator.h"
#include "direct_abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct parameter_type_list *
parameter_type_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_type_list *buff =
    calloc (1, sizeof (struct parameter_type_list));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_TYPE_LIST;
  buff->pl = ptr;
  buff->ellipsis = 1;
  buff->pl->parent_kind = NODE_PARAMETER_TYPE_LIST;
  buff->pl->parent = buff;

  return buff;
}

struct parameter_type_list *
parameter_type_list_2 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_type_list *buff =
    calloc (1, sizeof (struct parameter_type_list));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_TYPE_LIST;
  buff->pl = ptr;
  buff->ellipsis = 0;
  buff->pl->parent_kind = NODE_PARAMETER_TYPE_LIST;
  buff->pl->parent = buff;

  return buff;
}
