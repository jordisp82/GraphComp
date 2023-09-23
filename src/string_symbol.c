#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "string_symbol.h"
#include "primary_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct string *
string_1 (const char *str)
{
  assert (str != NULL);

  struct string *buff = calloc (1, sizeof (struct string));
  assert (buff != NULL);
  buff->kind = NODE_STRING;
  buff->str_kind = STRING_STRING;
  buff->str = strdup (str);
  assert (buff->str != NULL);

  return buff;
}

struct string *
string_2 (const char *str)
{
  assert (str != NULL);

  struct string *buff = calloc (1, sizeof (struct string));
  assert (buff != NULL);
  buff->kind = NODE_STRING;
  buff->str_kind = STRING_FUNC_NAME;
  buff->str = strdup (str);
  assert (buff->str != NULL);

  return buff;
}
