#include <assert.h>
#include <stdlib.h>

#include "type_qualifier.h"
#include "declaration_specifiers.h"
#include "specifier_qualifier_list.h"
#include "type_qualifier_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void tq_create_symtable (struct type_qualifier *buff);

struct type_qualifier *
type_qualifier_1 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_CONST;
  buff->create_symtable = tq_create_symtable;

  return buff;
}

struct type_qualifier *
type_qualifier_2 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_RESTRICT;
  buff->create_symtable = tq_create_symtable;

  return buff;
}

struct type_qualifier *
type_qualifier_3 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_VOLATILE;
  buff->create_symtable = tq_create_symtable;

  return buff;
}

struct type_qualifier *
type_qualifier_4 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_ATOMIC;
  buff->create_symtable = tq_create_symtable;

  return buff;
}

static void
tq_create_symtable (struct type_qualifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TYPE_QUALIFIER);

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

    case NODE_TYPE_QUALIFIER_LIST:
      buff->sym_table =
        ((struct type_qualifier_list *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }
}
