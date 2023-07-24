#include <assert.h>
#include <stdlib.h>

#include "type_qualifier_list.h"
#include "type_qualifier.h"
#include "direct_declarator.h"
#include "direct_abstract_declarator.h"
#include "pointer.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void tql_create_symtable (struct type_qualifier_list *buff);
static void tql_create_symbol (struct type_qualifier_list *buff);

struct type_qualifier_list *
type_qualifier_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct type_qualifier_list *buff =
    calloc (1, sizeof (struct type_qualifier_list));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER_LIST;
  buff->first = calloc (1, sizeof (struct tql_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->tq = ptr;
  buff->first->tq->parent_kind = NODE_TYPE_QUALIFIER_LIST;
  buff->first->tq->parent = buff;
  buff->create_symtable = tql_create_symtable;
  buff->create_symbol = tql_create_symbol;

  return buff;
}

struct type_qualifier_list *
type_qualifier_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_qualifier_list *buff = ptr1;
  struct type_qualifier *tq = ptr2;

  buff->last->next = calloc (1, sizeof (struct tql_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->tq = tq;
  tq->parent_kind = NODE_TYPE_QUALIFIER_LIST;
  tq->parent = buff;
  buff->create_symtable = tql_create_symtable;
  buff->create_symbol = tql_create_symbol;

  return buff;
}

static void
tql_create_symtable (struct type_qualifier_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TYPE_QUALIFIER_LIST);

  switch (buff->parent_kind)
    {
    case NODE_TYPE_QUALIFIER_LIST:
      buff->sym_table =
        ((struct type_qualifier_list *) (buff->parent))->sym_table;
      break;

    case NODE_DIRECT_DECLARATOR:
      buff->sym_table =
        ((struct direct_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_POINTER:
      buff->sym_table = ((struct pointer *) (buff->parent))->sym_table;
      break;

    case NODE_DIRECT_ABSTRACT_DECLARATOR:
      buff->sym_table =
        ((struct direct_abstract_declarator *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  for (struct tql_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->tq->create_symtable (ptr->tq);
}

static void
tql_create_symbol (struct type_qualifier_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TYPE_QUALIFIER_LIST);
  assert (buff->sym_table != NULL);

  for (struct tql_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->tq->create_symbol (ptr->tq);
}
