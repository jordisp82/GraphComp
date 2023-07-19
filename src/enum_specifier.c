#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "enum_specifier.h"
#include "enumerator_list.h"
#include "type_specifier.h"
#include "symbol.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void es_create_symtable (struct enum_specifier *buff);
static void es_create_symbol (struct enum_specifier *buff);

struct enum_specifier *
enum_specifier_1 (void *ptr)
{
  assert (ptr != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->el = ptr;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;
  buff->create_symtable = es_create_symtable;
  buff->create_symbol = es_create_symbol;

  return buff;
}

struct enum_specifier *
enum_specifier_2 (void *ptr)
{
  assert (ptr != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->el = ptr;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;
  buff->create_symtable = es_create_symtable;
  buff->create_symbol = es_create_symbol;

  return buff;
}

struct enum_specifier *
enum_specifier_3 (const char *str, void *ptr2)
{
  assert (str != NULL);
  assert (ptr2 != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->tag = strdup (str);
  buff->el = ptr2;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;
  buff->create_symtable = es_create_symtable;
  buff->create_symbol = es_create_symbol;

  return buff;
}

struct enum_specifier *
enum_specifier_4 (const char *str, void *ptr2)
{
  assert (str != NULL);
  assert (ptr2 != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->tag = strdup (str);
  buff->el = ptr2;
  buff->el->parent_kind = NODE_ENUM_SPECIFIER;
  buff->el->parent = buff;
  buff->create_symtable = es_create_symtable;
  buff->create_symbol = es_create_symbol;

  return buff;
}

struct enum_specifier *
enum_specifier_5 (const char *str)
{
  assert (str != NULL);

  struct enum_specifier *buff = calloc (1, sizeof (struct enum_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ENUM_SPECIFIER;
  buff->tag = strdup (str);
  buff->create_symtable = es_create_symtable;
  buff->create_symbol = es_create_symbol;

  return buff;
}

static void
es_create_symtable (struct enum_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUM_SPECIFIER);

  buff->sym_table = ((struct type_specifier *) (buff->parent))->sym_table;
  if (buff->el != NULL)
    buff->el->create_symtable (buff->el);

  if (buff->tag != NULL)
    {
      symbol_t *sym = calloc (1, sizeof (symbol_t));
      assert (sym != NULL);
      sym->name = strdup (buff->tag);
      sym->sym_ns = SYM_NS_TAG;
      sym->node = buff;
      sym->node_kind = NODE_ENUM_SPECIFIER;
      buff->sym_table->tags = avl_add_create (buff->sym_table->tags, sym);
    }
}

static void
es_create_symbol (struct enum_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUM_SPECIFIER);
  assert (buff->sym_table != NULL);

  if (buff->el != NULL)
    buff->el->create_symbol (buff->el);
}
