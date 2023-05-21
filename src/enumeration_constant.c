#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "enumeration_constant.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct enumeration_constant *
enumeration_constant_1 (const char *str)
{
  assert (str != NULL);

  struct enumeration_constant *buff =
    calloc (1, sizeof (struct enumeration_constant));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATION_CONSTANT;
  buff->str = strdup (str);
  assert (buff->str != NULL);
  
  /* TODO
   * add enumeration constant
   */

  return buff;
}
