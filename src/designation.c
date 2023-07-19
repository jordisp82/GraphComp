#include <assert.h>
#include <stdlib.h>

#include "designation.h"
#include "designator_list.h"
#include "initializer_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void d_create_symtable (struct designation *buff);
static void d_create_symbol (struct designation *buff);

struct designation *
designation_1 (void *ptr)
{
  assert (ptr != NULL);

  struct designation *buff = calloc (1, sizeof (struct designation));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATION;
  buff->dl = ptr;
  buff->dl->parent_kind = NODE_DESIGNATION;
  buff->dl->parent = buff;
  buff->create_symtable = d_create_symtable;
  buff->create_symbol = d_create_symbol;

  return buff;
}

static void
d_create_symtable (struct designation *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATION);

  buff->sym_table = ((struct initializer_list *) (buff->parent))->sym_table;
  if (buff->dl != NULL)
    buff->dl->create_symtable (buff->dl);
}

static void
d_create_symbol (struct designation *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATION);
  assert (buff->sym_table != NULL);

  if (buff->dl != NULL)
    buff->dl->create_symbol (buff->dl);
}
