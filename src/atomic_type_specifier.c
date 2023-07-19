#include <assert.h>
#include <stdlib.h>

#include "atomic_type_specifier.h"
#include "type_name.h"
#include "type_specifier.h"

static void ats_create_symtable (struct atomic_type_specifier *buff);
static void ats_create_symbol (struct atomic_type_specifier *buff);

#ifndef NULL
#define NULL ((void*)0)
#endif

struct atomic_type_specifier *
atomic_type_specifier_1 (void *ptr)
{
  assert (ptr != NULL);

  struct atomic_type_specifier *buff =
    calloc (1, sizeof (struct atomic_type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ATOMIC_TYPE_SPECIFIER;
  buff->tn = ptr;
  buff->tn->parent_kind = NODE_ATOMIC_TYPE_SPECIFIER;
  buff->tn->parent = buff;
  buff->create_symtable = ats_create_symtable;

  return buff;
}

static void
ats_create_symtable (struct atomic_type_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ATOMIC_TYPE_SPECIFIER);

  buff->sym_table = ((struct type_specifier *) (buff->parent))->sym_table;
  if (buff->tn != NULL)
    buff->tn->create_symtable (buff->tn);
}

static void
ats_create_symbol (struct atomic_type_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ATOMIC_TYPE_SPECIFIER);
  assert (buff->sym_table != NULL);

  if (buff->tn != NULL)
    buff->tn->create_symbol (buff->tn);
}
