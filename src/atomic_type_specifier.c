#include <assert.h>
#include <stdlib.h>

#include "atomic_type_specifier.h"
#include "type_name.h"
#include "type_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct atomic_type_specifier *
atomic_type_specifier_1 (void *ptr)
{
  assert (ptr != NULL);

  struct atomic_type_specifier *buff =
    calloc (1, sizeof (struct atomic_type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ATOMIC_TYPE_SPECIFIER;
  buff->tn = ptr;
  buff->tn->parent_kind = NODE_ATOMIC_TYPE_SPECIFIER;
  buff->tn->parent = buff;

  return buff;
}

void
set_atomic_specifier_scope (struct atomic_type_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ATOMIC_TYPE_SPECIFIER);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_TYPE_SPECIFIER:
        set_type_specifier_scope (buff->parent);
        buff->scope = ((struct type_specifier *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct type_specifier *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
