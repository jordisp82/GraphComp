#include <assert.h>
#include <stdlib.h>

#include "function_specifier.h"
#include "declaration_specifiers.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct function_specifier *
function_specifier_1 (void)
{
  struct function_specifier *buff =
    calloc (1, sizeof (struct function_specifier));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_SPECIFIER;
  buff->fs_kind = FS_INLINE;

  return buff;
}

struct function_specifier *
function_specifier_2 (void)
{
  struct function_specifier *buff =
    calloc (1, sizeof (struct function_specifier));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_SPECIFIER;
  buff->fs_kind = FS_NORETURN;

  return buff;
}

