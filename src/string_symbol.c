#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "string_symbol.h"
#include "primary_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void s_create_symtable (struct string *buff);
static void s_create_symbol (struct string *buff);

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
  buff->create_symtable = s_create_symtable;
  buff->create_symbol = s_create_symbol;

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
  buff->create_symtable = s_create_symtable;
  buff->create_symbol = s_create_symbol;

  return buff;
}

static void
s_create_symtable (struct string *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRING);

  buff->sym_table = ((struct primary_expression *) (buff->parent))->sym_table;
}

static void
s_create_symbol (struct string *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRING);
  assert (buff->sym_table != NULL);

  /* nothing to do */
}
