#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "declaration.h"
#include "declaration_specifiers.h"
#include "init_declarator_list.h"
#include "static_assert_declaration.h"
#include "external_declaration.h"
#include "block_item.h"
#include "block_item_list.h"
#include "declaration_list.h"
#include "function_definition.h"
#include "ast.h"
#include "iteration_statement.h"
#include "declaration_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void d_create_symtable (struct declaration *buff);
static void d_create_symbol (struct declaration *buff);

struct declaration *
declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr;
  buff->ds->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff;
  buff->create_symtable = d_create_symtable;
  buff->create_symbol = d_create_symbol;

  return buff;
}

struct declaration *
declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr1;
  buff->idl = ptr2;
  buff->ds->parent_kind = buff->idl->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff->idl->parent = buff;
  buff->create_symtable = d_create_symtable;
  buff->create_symbol = d_create_symbol;

  if (look_for_typedef (buff->ds) == 1)
    register_ids_as_typedef (buff->idl);

  return buff;
}

struct declaration *
declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->sad = ptr;
  buff->sad->parent_kind = NODE_DECLARATION;
  buff->sad->parent = buff;
  buff->create_symtable = d_create_symtable;
  buff->create_symbol = d_create_symbol;

  return buff;
}

static void
d_create_symtable (struct declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION);

  switch (buff->parent_kind)
    {
    case NODE_BLOCK_ITEM:
      buff->sym_table = ((struct block_item *) (buff->parent))->sym_table;
      break;

    case NODE_ITERATION_STATEMENT:
      buff->sym_table =
        ((struct iteration_statement *) (buff->parent))->sym_table;
      break;

    case NODE_EXTERNAL_DECLARATION:
      buff->sym_table =
        ((struct external_declaration *) (buff->parent))->sym_table;
      break;

    case NODE_DECLARATION_LIST:
      buff->sym_table =
        ((struct declaration_list *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->ds != NULL)
    buff->ds->create_symtable (buff->ds);
  if (buff->idl != NULL)
    buff->idl->create_symtable (buff->idl);
  /* fuck off static assert declarations */
}

static void
d_create_symbol (struct declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION);
  assert (buff->sym_table != NULL);

  if (buff->ds != NULL)
    buff->ds->create_symbol (buff->ds);
  if (buff->idl != NULL)
    buff->idl->create_symbol (buff->idl);
  /* fuck off static assert declarations */
}
