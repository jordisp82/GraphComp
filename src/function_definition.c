#include <assert.h>
#include <stdlib.h>

#include "function_definition.h"
#include "declaration_specifiers.h"
#include "declarator.h"
#include "declaration_list.h"
#include "compound_statement.h"
#include "direct_declarator.h"
#include "external_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void fd_create_symtable (struct function_definition *buff);
static void fd_create_symbol (struct function_definition *buff);

struct function_definition *
function_definition_1 (void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);
  assert (ptr4 != NULL);

  struct function_definition *buff =
    calloc (1, sizeof (struct function_definition));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_DEFINITION;
  buff->fd_kind = FD_K_AND_R;
  buff->ds = ptr1;
  buff->dr = ptr2;
  buff->dl = ptr3;
  buff->cs = ptr4;
  buff->ds->parent_kind = buff->dr->parent_kind = buff->dl->parent_kind =
    buff->cs->parent_kind = NODE_FUNCTION_DEFINITION;
  buff->ds->parent = buff->dr->parent = buff->dl->parent = buff->cs->parent =
    buff;
  buff->create_symtable = fd_create_symtable;
  buff->create_symbol = fd_create_symbol;

  return buff;
}

struct function_definition *
function_definition_2 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);
  struct function_definition *buff =
    calloc (1, sizeof (struct function_definition));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_DEFINITION;
  buff->fd_kind = FD_STANDARD_C;
  buff->ds = ptr1;
  buff->dr = ptr2;
  buff->cs = ptr3;
  buff->ds->parent_kind = buff->dr->parent_kind = buff->cs->parent_kind =
    NODE_FUNCTION_DEFINITION;
  buff->ds->parent = buff->dr->parent = buff->cs->parent = buff;
  buff->create_symtable = fd_create_symtable;
  buff->create_symbol = fd_create_symbol;

  return buff;
}

static void
fd_create_symtable (struct function_definition *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_FUNCTION_DEFINITION);

  buff->sym_table =
    ((struct external_declaration *) (buff->parent))->sym_table;

  if (buff->ds != NULL)
    buff->ds->create_symtable (buff->ds);
  if (buff->dr != NULL)
    buff->dr->create_symtable (buff->dr);
  if (buff->dl != NULL)
    buff->dl->create_symtable (buff->dl);
  if (buff->cs != NULL)
    buff->cs->create_symtable (buff->cs);

  /*
   * NOTE in the case of a K&R-style function definition,
   * the parameters are declared in the declaration-list
   * and their scope shall be set as that of the
   * compound statement.
   */
  if (buff->dl != NULL && buff->cs != NULL)
    buff->dl->sym_table = buff->cs->sym_table;
}

static void
fd_create_symbol (struct function_definition *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_FUNCTION_DEFINITION);
  assert (buff->sym_table != NULL);

  if (buff->ds != NULL)
    buff->ds->create_symbol (buff->ds);
  if (buff->dr != NULL)
    buff->dr->create_symbol (buff->dr);
  if (buff->dl != NULL)
    buff->dl->create_symbol (buff->dl);
  if (buff->cs != NULL)
    buff->cs->create_symbol (buff->cs);
}
