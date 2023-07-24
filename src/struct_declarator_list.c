#include <assert.h>
#include <stdlib.h>

#include "struct_declarator_list.h"
#include "struct_declarator.h"
#include "struct_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sdl_create_symtable (struct struct_declarator_list *buff);
static void sdl_create_symbol (struct struct_declarator_list *buff);

struct struct_declarator_list *
struct_declarator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declarator_list *buff =
    calloc (1, sizeof (struct struct_declarator_list));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATOR_LIST;
  buff->first = calloc (1, sizeof (struct sdl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->sd = ptr;
  buff->first->sd->parent_kind = NODE_STRUCT_DECLARATOR_LIST;
  buff->first->sd->parent = buff;
  buff->create_symtable = sdl_create_symtable;
  buff->create_symbol = sdl_create_symbol;

  return buff;
}

struct struct_declarator_list *
struct_declarator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declarator_list *buff = ptr1;
  struct struct_declarator *d = ptr2;

  buff->last->next = calloc (1, sizeof (struct sdl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->sd = d;
  d->parent_kind = NODE_STRUCT_DECLARATOR_LIST;
  d->parent = buff;
  buff->create_symtable = sdl_create_symtable;
  buff->create_symbol = sdl_create_symbol;

  return buff;
}

static void
sdl_create_symtable (struct struct_declarator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_DECLARATOR_LIST);

  switch (buff->parent_kind)
    {
    case NODE_STRUCT_DECLARATOR_LIST:
      buff->sym_table =
        ((struct struct_declarator_list *) (buff->parent))->sym_table;
      break;

    case NODE_STRUCT_DECLARATION:
      buff->sym_table =
        ((struct struct_declaration *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  for (struct sdl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->sd->create_symtable (ptr->sd);
}

static void
sdl_create_symbol (struct struct_declarator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_DECLARATOR_LIST);
  assert (buff->sym_table != NULL);

  for (struct sdl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->sd->create_symbol (ptr->sd);
}
