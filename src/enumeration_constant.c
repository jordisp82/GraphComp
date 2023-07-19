#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "enumeration_constant.h"
#include "enumerator.h"
#include "symbol.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ec_create_symtable (struct enumeration_constant *buff);
static void ec_create_symbol (struct enumeration_constant *buff);

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
  buff->create_symbol = ec_create_symbol;

  add_enumeration_constant (str);

  return buff;
}

static void
ec_create_symtable (struct enumeration_constant *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATION_CONSTANT);

  buff->sym_table = ((struct enumerator *) (buff->parent))->sym_table;

  struct symbol *sym = calloc (1, sizeof (struct symbol));
  assert (sym != NULL);
  sym->name = strdup (buff->str);
  assert (sym->name != NULL);
  sym->node = buff;
  sym->node_kind = NODE_ENUMERATION_CONSTANT;
  sym->sym_ns = SYM_NS_ORDINARY;
  buff->sym_table->ord = avl_add_create (buff->sym_table->ord, sym);
}

static void
ec_create_symbol (struct enumeration_constant *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATION_CONSTANT);
  assert (buff->sym_table != NULL);

  /* NOTE nothing to be done */
}
