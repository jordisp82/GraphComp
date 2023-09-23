#include <assert.h>
#include <stdlib.h>

#include "struct_or_union.h"
#include "struct_or_union_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct struct_or_union *
struct_or_union_1 (void)
{
  struct struct_or_union *buff = calloc (1, sizeof (struct struct_or_union));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION;
  buff->value = SU_STRUCT;

  return buff;
}

struct struct_or_union *
struct_or_union_2 (void)
{
  struct struct_or_union *buff = calloc (1, sizeof (struct struct_or_union));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION;
  buff->value = SU_UNION;

  return buff;
}
