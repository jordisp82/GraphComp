#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "type_specifier.h"
#include "atomic_type_specifier.h"
#include "struct_or_union_specifier.h"
#include "enum_specifier.h"
#include "declaration_specifiers.h"
#include "specifier_qualifier_list.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ts_create_symtable (struct type_specifier *buff);
static void ts_create_symbol (struct type_specifier *buff);

struct type_specifier *
type_specifier_1 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_VOID;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_2 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_CHAR;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_3 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_SHORT;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_4 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_INT;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_5 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_LONG;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_6 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_FLOAT;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_7 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_DOUBLE;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_8 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_SIGNED;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_9 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_UNSIGNED;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_10 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_BOOL;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_11 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_COMPLEX;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_12 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_IMAGINARY;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_13 (void *ptr)
{
  assert (ptr != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_ATOMIC;
  buff->ats = ptr;
  buff->ats->parent_kind = NODE_TYPE_SPECIFIER;
  buff->ats->parent = buff;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_14 (void *ptr)
{
  assert (ptr != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_STRUCT_UNION;
  buff->sus = ptr;
  buff->sus->parent_kind = NODE_TYPE_SPECIFIER;
  buff->sus->parent = buff;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_15 (void *ptr)
{
  assert (ptr != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_ENUM;
  buff->es = ptr;
  buff->es->parent_kind = NODE_TYPE_SPECIFIER;
  buff->es->parent = buff;
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

struct type_specifier *
type_specifier_16 (const char *str)
{
  assert (str != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_TYPEDEF;
  buff->typedef_name = strdup (str);
  assert (buff->typedef_name != NULL);
  buff->create_symtable = ts_create_symtable;
  buff->create_symbol = ts_create_symbol;

  return buff;
}

static void
ts_create_symtable (struct type_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TYPE_SPECIFIER);

  switch (buff->parent_kind)
    {
    case NODE_DECLARATION_SPECIFIERS:
      buff->sym_table =
        ((struct declaration_specifiers *) (buff->parent))->sym_table;
      break;

    case NODE_SPECIFIER_QUALIFIER_LIST:
      buff->sym_table =
        ((struct specifier_qualifier_list *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  switch (buff->ts_kind)
    {
    case TS_ATOMIC:
      buff->ats->create_symtable (buff->ats);
      break;

    case TS_STRUCT_UNION:
      buff->sus->create_symtable (buff->sus);
      break;

    case TS_ENUM:
      buff->es->create_symtable (buff->es);
      break;

    case TS_VOID:
    case TS_CHAR:
    case TS_SHORT:
    case TS_INT:
    case TS_LONG:
    case TS_FLOAT:
    case TS_DOUBLE:
    case TS_SIGNED:
    case TS_UNSIGNED:
    case TS_BOOL:
    case TS_COMPLEX:
    case TS_IMAGINARY:
    case TS_TYPEDEF:
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
ts_create_symbol (struct type_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TYPE_SPECIFIER);
  assert (buff->sym_table != NULL);

  avl_node_t *node = NULL;

  /*
   * It's not a problem if the search into
   * the AVL tree returns NULL: maybe there
   * is no tag in the struct or union or enum
   * specifier, or this declaration is the
   * one introducing the tag and therefore
   * it's not yet in the symbol table.
   */

  switch (buff->ts_kind)
    {
    case TS_STRUCT_UNION:
      if (buff->sus->tag != NULL)
        node = avl_search (buff->sym_table->tags, buff->sus->tag);
      if (node != NULL)
        buff->sym = node->value;
      break;

    case TS_ENUM:
      if (buff->es->tag != NULL)
        node = avl_search (buff->sym_table->tags, buff->es->tag);
      if (node != NULL)
        buff->sym = node->value;
      break;

    default:
      break;                    /* not necessarily a bug */
    }
}
