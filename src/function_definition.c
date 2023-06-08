#include <assert.h>
#include <stdlib.h>

#include "function_definition.h"
#include "declaration_specifiers.h"
#include "declarator.h"
#include "declaration_list.h"
#include "compound_statement.h"
#include "direct_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

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

  return buff;
}

int
create_symbols_for_function_definition (struct function_definition *buff,
                                        symbol_t ** sym_fd,
                                        symbol_t *** sym_pars)
{
  assert (buff != NULL);
  assert (sym_fd != NULL);
  assert (sym_pars != NULL);
  assert (buff->kind == NODE_FUNCTION_DEFINITION);

  *sym_fd = create_symbol_for_declarator (buff->dr);
  (*sym_fd)->scope = buff->parent;
  (*sym_fd)->scope_kind = NODE_TRANSLATION_UNIT;

  int n = create_symbols_for_parameters (buff->dr, sym_pars);
  for (int i = 0; i < n; i++)
    if ((*sym_pars)[i] != NULL)
      {
        (*sym_pars)[i]->scope = buff->cs;
        (*sym_pars)[i]->scope_kind = NODE_COMPOUND_STATEMENT;
      }

  return n;
}

void
create_symbol_table_fd (struct function_definition *buff, int n,
                        symbol_t ** sym_pars)
{
  assert (buff != NULL);
  assert (sym_pars != NULL);
  assert (buff->kind == NODE_FUNCTION_DEFINITION);

  if (n > 0)
    {
      buff->cs->ordinary = avl_create (sym_pars[0]);
      for (int i = 1; i < n; i++)
        avl_add (buff->cs->ordinary, sym_pars[i]);
    }

  create_symbol_table_cs (buff->cs);
}

void
set_symbol_for_function_definition (struct function_definition *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_FUNCTION_DEFINITION);
  assert (buff->cs != NULL);

  set_symbol_for_compound_stmt (buff->cs);
}

#if 0
/* currently unused */
const char *
get_function_definition_name (struct function_definition *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_FUNCTION_DEFINITION);

  switch (buff->dr->ddclr->n_prod)
    {
    case 12:
    case 13:
    case 14:
      if (buff->dr->ddclr->ddeclr->n_prod == 1)
        return buff->dr->ddclr->ddeclr->id;
      break;

    default:
      return NULL;
    }

  return NULL;
}
#endif
