#include <assert.h>
#include <stdlib.h>

#include "struct_declaration_list.h"
#include "struct_declaration.h"
#include "struct_or_union_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sdl_create_symtable (struct struct_declaration_list *buff);
static void sdl_create_symbol (struct struct_declaration_list *buff);

struct struct_declaration_list *
struct_declaration_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declaration_list *buff =
    calloc (1, sizeof (struct struct_declaration_list));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION_LIST;
  buff->first = calloc (1, sizeof (struct sdln_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->sd = ptr;
  buff->first->sd->parent_kind = NODE_STRUCT_DECLARATION_LIST;
  buff->first->sd->parent = buff;
  buff->create_symtable = sdl_create_symtable;
  buff->create_symbol = sdl_create_symbol;

  return buff;
}

struct struct_declaration_list *
struct_declaration_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declaration_list *buff = ptr1;
  struct struct_declaration *sd = ptr2;

  buff->last->next = calloc (1, sizeof (struct sdln_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->sd = sd;
  sd->parent_kind = NODE_STRUCT_DECLARATION_LIST;
  sd->parent = sd;
  buff->create_symtable = sdl_create_symtable;
  buff->create_symbol = sdl_create_symbol;

  return buff;
}

static void
sdl_create_symtable (struct struct_declaration_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_DECLARATION_LIST);

  buff->sym_table =
    ((struct struct_or_union_specifier *) (buff->parent))->sym_table;
  for (struct sdln_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->sd->create_symtable (ptr->sd);
}

static void
sdl_create_symbol (struct struct_declaration_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_DECLARATION_LIST);
  assert (buff->sym_table != NULL);

  for (struct sdln_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->sd->create_symbol (ptr->sd);
}
