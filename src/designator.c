#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "designator.h"
#include "constant_expression.h"
#include "designator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void d_create_symtable (struct designator *buff);
static void d_create_symbol (struct designator *buff);

struct designator *
designator_1 (void *ptr)
{
  assert (ptr != NULL);

  struct designator *buff = calloc (1, sizeof (struct designator));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR;
  buff->d_kind = DESIGNATOR_ARRAY;
  buff->ex = ptr;
  buff->ex->parent_kind = NODE_DESIGNATOR;
  buff->ex->parent = buff;
  buff->create_symtable = d_create_symtable;
  buff->create_symbol = d_create_symbol;

  return buff;
}

struct designator *
designator_2 (const char *str)
{
  assert (str != NULL);

  struct designator *buff = calloc (1, sizeof (struct designator));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR;
  buff->d_kind = DESIGNATOR_FIELD;
  buff->str = strdup (str);
  assert (buff->str != NULL);
  buff->create_symtable = d_create_symtable;
  buff->create_symbol = d_create_symbol;

  return buff;
}

static void
d_create_symtable (struct designator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATOR);

  buff->sym_table = ((struct designator_list *) (buff->parent))->sym_table;
  if (buff->ex != NULL)
    buff->ex->create_symtable (buff->ex);
}

static void
d_create_symbol (struct designator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATOR);
  assert (buff->sym_table != NULL);

  if (buff->ex != NULL)
    buff->ex->create_symbol (buff->ex);
}
