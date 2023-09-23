#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "enum_specifier.h"
#include "enumerator_list.h"
#include "type_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct enum_specifier *
enum_specifier_1 (void *ptr)
{
  assert (ptr != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->el = ptr;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;

  return buff;
}

struct enum_specifier *
enum_specifier_2 (void *ptr)
{
  assert (ptr != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->el = ptr;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;

  return buff;
}

struct enum_specifier *
enum_specifier_3 (const char *str, void *ptr2)
{
  assert (str != NULL);
  assert (ptr2 != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->tag = strdup (str);
  buff->el = ptr2;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;

  return buff;
}

struct enum_specifier *
enum_specifier_4 (const char *str, void *ptr2)
{
  assert (str != NULL);
  assert (ptr2 != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->tag = strdup (str);
  buff->el = ptr2;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;

  return buff;
}

struct enum_specifier *
enum_specifier_5 (const char *str)
{
  assert (str != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->tag = strdup (str);

  return buff;
}
