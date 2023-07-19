#include <assert.h>
#include <stdlib.h>

#include "declaration_list.h"
#include "declaration.h"
#include "function_definition.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void dl_create_symtable (struct declaration_list *buff);
static void dl_create_symbol (struct declaration_list *buff);

struct declaration_list *
declaration_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_list *buff =
    calloc (1, sizeof (struct declaration_list));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_LIST;
  buff->first = calloc (1, sizeof (struct dl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->dl = ptr;
  buff->first->dl->parent_kind = NODE_DECLARATION_LIST;
  buff->first->dl->parent = buff;
  buff->create_symtable = dl_create_symtable;
  buff->create_symbol = dl_create_symbol;

  return buff;
}

struct declaration_list *
declaration_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declaration_list *buff = ptr1;
  struct declaration *dl = ptr2;

  buff->last->next = calloc (1, sizeof (struct dl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->dl = dl;
  dl->parent_kind = NODE_DECLARATION_LIST;
  dl->parent = buff;
  buff->create_symtable = dl_create_symtable;
  buff->create_symbol = dl_create_symbol;

  return buff;
}

static void
dl_create_symtable (struct declaration_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION_LIST);

  buff->sym_table =
    ((struct function_definition *) (buff->parent))->sym_table;
  for (struct dl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->dl->create_symtable (ptr->dl);
}

static void
dl_create_symbol (struct declaration_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION_LIST);
  assert (buff->sym_table != NULL);

  buff->sym_table =
    ((struct function_definition *) (buff->parent))->sym_table;
  for (struct dl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->dl->create_symbol (ptr->dl);
}
