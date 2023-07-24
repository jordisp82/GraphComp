#include <assert.h>
#include <stdlib.h>

#include "storage_class_specifier.h"
#include "declaration_specifiers.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void scs_create_symtable (struct storage_class_specifier *buff);
static void scs_create_symbol (struct storage_class_specifier *buff);

struct storage_class_specifier *
storage_class_specifier_1 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_TYPEDEF;
  buff->create_symtable = scs_create_symtable;
  buff->create_symbol = scs_create_symbol;

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
  buff->create_symtable = scs_create_symtable;
  buff->create_symbol = scs_create_symbol;

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
  buff->create_symtable = scs_create_symtable;
  buff->create_symbol = scs_create_symbol;

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
  buff->create_symtable = scs_create_symtable;
  buff->create_symbol = scs_create_symbol;

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
  buff->create_symtable = scs_create_symtable;
  buff->create_symbol = scs_create_symbol;

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
  buff->create_symtable = scs_create_symtable;
  buff->create_symbol = scs_create_symbol;

  return buff;
}

static void
scs_create_symtable (struct storage_class_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STORAGE_CLASS_SPECIFIER);

  buff->sym_table =
    ((struct declaration_specifiers *) (buff->parent))->sym_table;
}

static void
scs_create_symbol (struct storage_class_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STORAGE_CLASS_SPECIFIER);
  assert (buff->sym_table != NULL);

  /* nothing to do */
}
