#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

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
