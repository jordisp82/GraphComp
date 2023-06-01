#include <assert.h>
#include <stdlib.h>

#include "designation.h"
#include "designator_list.h"
#include "initializer_list.h"

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
  buff->dl->parent_kind = NODE_DESIGNATION;
  buff->dl->parent = buff;

  return buff;
}

void
set_designation_scope (struct designation *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATION);

  switch (buff->parent_kind)
    {
    case NODE_INITIALIZER_LIST:
      set_initializer_list_scope (buff->parent);
      buff->scope = ((struct initializer_list *) (buff->parent))->scope;
      buff->scope_kind =
        ((struct initializer_list *) (buff->parent))->scope_kind;
      break;

    default:
      ;                         /* BUG! */
    }
}
