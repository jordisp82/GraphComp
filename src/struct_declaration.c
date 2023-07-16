#include <assert.h>
#include <stdlib.h>

#include "struct_declaration.h"
#include "specifier_qualifier_list.h"
#include "struct_declarator_list.h"
#include "static_assert_declaration.h"
#include "struct_declaration_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sd_create_symtable (struct struct_declaration *buff);

struct struct_declaration *
struct_declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declaration *buff =
    calloc (1, sizeof (struct struct_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION;
  buff->sql = ptr;
  buff->sql->parent_kind = NODE_STRUCT_DECLARATION;
  buff->sql->parent = buff;
  buff->create_symtable = sd_create_symtable;

  return buff;
}

struct struct_declaration *
struct_declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declaration *buff =
    calloc (1, sizeof (struct struct_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION;
  buff->sql = ptr1;
  buff->sdl = ptr2;
  buff->sql->parent_kind = buff->sdl->parent_kind = NODE_STRUCT_DECLARATION;
  buff->sql->parent = buff->sdl->parent = buff;
  buff->create_symtable = sd_create_symtable;

  return buff;
}

struct struct_declaration *
struct_declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declaration *buff =
    calloc (1, sizeof (struct struct_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION;
  buff->sad = ptr;
  buff->sad->parent_kind = NODE_STRUCT_DECLARATION;
  buff->sad->parent = buff;
  buff->create_symtable = sd_create_symtable;

  return buff;
}

static void
sd_create_symtable (struct struct_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_DECLARATION);

  buff->sym_table =
    ((struct struct_declaration_list *) (buff->parent))->sym_table;
  if (buff->sql != NULL)
    buff->sql->create_symtable (buff->sql);
  if (buff->sdl != NULL)
    buff->sdl->create_symtable (buff->sdl);
  if (buff->sad != NULL)
    buff->sad->create_symtable (buff->sad);
}

#if 0
void
set_struct_declaration_scope (struct struct_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_DECLARATION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_STRUCT_DECLARATION_LIST:
        set_struct_declaration_list_scope (buff->parent);
        buff->scope =
          ((struct struct_declaration_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct struct_declaration_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
#endif
