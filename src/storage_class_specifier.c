#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "storage_class_specifier.h"
#include "declaration_specifiers.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct storage_class_specifier *
storage_class_specifier_1 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_TYPEDEF;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_2 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_EXTERN;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_3 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_STATIC;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_4 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_THREAD_LOCAL;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_5 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_AUTO;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_6 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_REGISTER;

  return buff;
}
