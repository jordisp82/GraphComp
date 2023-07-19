#include <assert.h>
#include <stdlib.h>

#include "function_specifier.h"
#include "declaration_specifiers.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

void fs_create_symtable (struct function_specifier *buff);
void fs_create_symbol (struct function_specifier *buff);

struct function_specifier *
function_specifier_1 (void)
{
  struct function_specifier *buff =
    calloc (1, sizeof (struct function_specifier));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_SPECIFIER;
  buff->fs_kind = FS_INLINE;
  buff->create_symtable = fs_create_symtable;
  buff->create_symbol = fs_create_symbol;

  return buff;
}

struct function_specifier *
function_specifier_2 (void)
{
  struct function_specifier *buff =
    calloc (1, sizeof (struct function_specifier));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_SPECIFIER;
  buff->fs_kind = FS_NORETURN;
  buff->create_symtable = fs_create_symtable;
  buff->create_symbol = fs_create_symbol;

  return buff;
}

void
fs_create_symtable (struct function_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_FUNCTION_SPECIFIER);

  buff->sym_table =
    ((struct declaration_specifiers *) (buff->parent))->sym_table;
}

void
fs_create_symbol (struct function_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_FUNCTION_SPECIFIER);
  assert (buff->sym_table != NULL);

  /* NOTE nothing to do */
}
