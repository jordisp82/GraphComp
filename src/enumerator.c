#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "enumerator.h"
#include "enumeration_constant.h"
#include "constant_expression.h"
#include "enumerator_list.h"
#include "symbol.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void e_create_symtable (struct enumerator *buff);
static void e_create_symbol (struct enumerator *buff);

struct enumerator *
enumerator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct enumerator *buff = calloc (1, sizeof (struct enumerator));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR;
  buff->e_kind = ENUM_WITH_CONST_EXPR;
  buff->ec = ptr1;
  buff->expr = ptr2;
  buff->ec->parent_kind = buff->expr->parent_kind = NODE_ENUMERATOR;
  buff->ec->parent = buff->expr->parent = buff;
  buff->create_symtable = e_create_symtable;
  buff->create_symbol = e_create_symbol;

  return buff;
}

struct enumerator *
enumerator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct enumerator *buff = calloc (1, sizeof (struct enumerator));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR;
  buff->e_kind = ENUM_NO_CONST_EXPR;
  buff->ec = ptr;
  buff->ec->parent_kind = NODE_ENUMERATOR;
  buff->ec->parent = buff;
  buff->create_symtable = e_create_symtable;
  buff->create_symbol = e_create_symbol;

  return buff;
}

static void
e_create_symtable (struct enumerator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATOR);

  buff->sym_table = ((struct enumerator_list *) (buff->parent))->sym_table;
  if (buff->ec != NULL)
    buff->ec->create_symtable (buff->ec);
  if (buff->expr != NULL)
    buff->expr->create_symtable (buff->expr);

  symbol_t *sym = calloc (1, sizeof (symbol_t));
  assert (sym != NULL);
  sym->name = strdup (buff->ec->str);
  sym->sym_ns = SYM_NS_ORDINARY;
  sym->node = buff;
  sym->node_kind = NODE_ENUMERATOR;

  buff->sym_table->ord = avl_add_create (buff->sym_table->ord, sym);
}

static void
e_create_symbol (struct enumerator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATOR);
  assert (buff->sym_table != NULL);

  if (buff->ec != NULL)
    buff->ec->create_symbol (buff->ec);
  if (buff->expr != NULL)
    buff->expr->create_symbol (buff->expr);
}
