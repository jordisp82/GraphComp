#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "enumeration_constant.h"
#include "enumerator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ec_create_symtable (struct enumeration_constant *buff);

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
  buff->create_symtable = ec_create_symtable;

  add_enumeration_constant (str);

  return buff;
}

static void
ec_create_symtable (struct enumeration_constant *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATION_CONSTANT);

  buff->sym_table = ((struct enumerator *) (buff->parent))->sym_table;
}
