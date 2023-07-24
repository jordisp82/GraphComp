#include <assert.h>
#include <stdlib.h>

#include "struct_or_union.h"
#include "struct_or_union_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void su_create_symtable (struct struct_or_union *buff);
static void su_create_symbol (struct struct_or_union *buff);

struct struct_or_union *
struct_or_union_1 (void)
{
  struct struct_or_union *buff = calloc (1, sizeof (struct struct_or_union));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION;
  buff->value = SU_STRUCT;
  buff->create_symtable = su_create_symtable;
  buff->create_symbol = su_create_symbol;

  return buff;
}

struct struct_or_union *
struct_or_union_2 (void)
{
  struct struct_or_union *buff = calloc (1, sizeof (struct struct_or_union));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION;
  buff->value = SU_UNION;
  buff->create_symtable = su_create_symtable;
  buff->create_symbol = su_create_symbol;

  return buff;
}

static void
su_create_symtable (struct struct_or_union *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_OR_UNION);

  buff->sym_table =
    ((struct struct_or_union_specifier *) (buff->parent))->sym_table;
}

static void
su_create_symbol (struct struct_or_union *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_OR_UNION);
  assert (buff->sym_table != NULL);

  /* nothing to do */
}
