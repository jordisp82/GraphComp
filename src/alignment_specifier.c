#include <assert.h>
#include <stdlib.h>

#include "alignment_specifier.h"
#include "type_name.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct alignment_specifier *
alignment_specifier_1 (void *ptr)
{
  assert (ptr != NULL);

  struct alignment_specifier *buff =
    calloc (1, sizeof (struct alignment_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ALIGNMENT_SPECIFIER;
  buff->a_kind = ALIGN_TYPE_NAME;
  buff->tn = ptr;
  buff->tn->parent_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->tn->parent = buff;

  return buff;
}

struct alignment_specifier *
alignment_specifier_2 (void *ptr)
{
  assert (ptr != NULL);

  struct alignment_specifier *buff =
    calloc (1, sizeof (struct alignment_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ALIGNMENT_SPECIFIER;
  buff->a_kind = ALIGN_CONST_EXPR;
  buff->expr = ptr;
#if 0
  buff->expr->parent_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->expr->parent = buff;
#endif

  return buff;
}
