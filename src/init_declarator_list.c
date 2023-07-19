#include <assert.h>
#include <stdlib.h>

#include "init_declarator_list.h"
#include "init_declarator.h"
#include "declaration.h"
#include "declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void idl_create_symtable (struct init_declarator_list *buff);
static void idl_create_symbol (struct init_declarator_list *buff);

struct init_declarator_list *
init_declarator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct init_declarator_list *buff =
    calloc (1, sizeof (struct init_declarator_list));
  assert (buff != NULL);
  buff->kind = NODE_INIT_DECLARATOR_LIST;
  buff->first = calloc (1, sizeof (struct idl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->id = ptr;
  buff->first->id->parent_kind = NODE_INIT_DECLARATOR_LIST;
  buff->first->id->parent = buff;
  buff->create_symtable = idl_create_symtable;
  buff->create_symbol = idl_create_symbol;

  return buff;
}

struct init_declarator_list *
init_declarator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct init_declarator_list *buff = ptr1;
  struct init_declarator *id = ptr2;

  buff->last->next = calloc (1, sizeof (struct idl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->id = id;
  id->parent_kind = NODE_INIT_DECLARATOR_LIST;
  id->parent = buff;
  buff->create_symtable = idl_create_symtable;
  buff->create_symbol = idl_create_symbol;

  return buff;
}

static void
idl_create_symtable (struct init_declarator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INIT_DECLARATOR_LIST);

  switch (buff->parent_kind)
    {
    case NODE_DECLARATION:
      buff->sym_table = ((struct declaration *) (buff->parent))->sym_table;
      break;

    case NODE_INIT_DECLARATOR_LIST:
      buff->sym_table =
        ((struct init_declarator_list *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  for (struct idl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->id->create_symtable (ptr->id);
}

static void
idl_create_symbol (struct init_declarator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INIT_DECLARATOR_LIST);
  assert (buff->sym_table != NULL);

  for (struct idl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->id->create_symbol (ptr->id);
}
