#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "constant.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct constant *
constant_1 (int value)
{
  struct constant *buff = calloc (1, sizeof (struct constant));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT;
  buff->const_kind = CONST_INTEGER;
  buff->integer = value;

  return buff;
}

struct constant *
constant_2 (double value)
{
  struct constant *buff = calloc (1, sizeof (struct constant));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT;
  buff->const_kind = CONST_FLOAT;
  buff->floating = value;

  return buff;
}

struct constant *
constant_3 (const char *str)
{
  assert (str != NULL);

  struct constant *buff = calloc (1, sizeof (struct constant));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT;
  buff->const_kind = CONST_ENUM;
  buff->string = strdup (str);
  assert (buff->string != NULL);

  return buff;
}
