#include <assert.h>
#include <stdlib.h>

#include "enumerator_list.h"
#include "enumerator.h"
#include "enum_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void el_create_symtable (struct enumerator_list *buff);
static void el_create_symbol (struct enumerator_list *buff);

struct enumerator_list *
enumerator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct enumerator_list *buff = calloc (1, sizeof (struct enumerator_list));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR_LIST;
  buff->first = calloc (1, sizeof (struct enl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->en = ptr;
  buff->first->en->parent_kind = NODE_ENUMERATOR_LIST;
  buff->first->en->parent = buff;
  buff->create_symtable = el_create_symtable;
  buff->create_symbol = el_create_symbol;

  return buff;
}

struct enumerator_list *
enumerator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct enumerator_list *buff = ptr1;
  struct enumerator *en = ptr2;

  buff->last->next = calloc (1, sizeof (struct enl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->en = en;
  en->parent_kind = NODE_ENUMERATOR_LIST;
  en->parent = buff;
  buff->create_symtable = el_create_symtable;
  buff->create_symbol = el_create_symbol;

  return buff;
}

static void
el_create_symtable (struct enumerator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATOR_LIST);

  switch (buff->parent_kind)
    {
    case NODE_ENUMERATOR_LIST:
      buff->sym_table =
        ((struct enumerator_list *) (buff->parent))->sym_table;
      break;

    case NODE_ENUM_SPECIFIER:
      buff->sym_table = ((struct enum_specifier *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  for (struct enl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->en->create_symtable (ptr->en);
}

static void
el_create_symbol (struct enumerator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATOR_LIST);
  assert (buff->sym_table != NULL);

  for (struct enl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->en->create_symbol (ptr->en);
}
