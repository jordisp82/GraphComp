#include <assert.h>
#include <stdlib.h>

#include "declarator.h"
#include "pointer.h"
#include "direct_declarator.h"
#include "init_declarator.h"
#include "struct_declarator.h"
#include "direct_declarator.h"
#include "parameter_declaration.h"
#include "function_definition.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void d_create_symtable (struct declarator *buff);

struct declarator *
declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declarator *buff = calloc (1, sizeof (struct declarator));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATOR;
  buff->dclr_kind = DCLR_WITH_POINTER;
  buff->ptr = ptr1;
  buff->ddclr = ptr2;
  buff->ptr->parent_kind = buff->ddclr->parent_kind = NODE_DECLARATOR;
  buff->ptr->parent = buff->ddclr->parent = buff;
  buff->create_symtable = d_create_symtable;

  return buff;
}

struct declarator *
declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct declarator *buff = calloc (1, sizeof (struct declarator));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATOR;
  buff->dclr_kind = DCLR_NO_POINTER;
  buff->ddclr = ptr;
  buff->ddclr->parent_kind = NODE_DECLARATOR;
  buff->ddclr->parent = buff;
  buff->create_symtable = d_create_symtable;

  return buff;
}

static void
d_create_symtable (struct declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATOR);

  switch (buff->parent_kind)
    {
    case NODE_INIT_DECLARATOR:
      buff->sym_table =
        ((struct init_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_STRUCT_DECLARATOR:
      buff->sym_table =
        ((struct struct_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_DIRECT_DECLARATOR:
      buff->sym_table =
        ((struct direct_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_PARAMETER_DECLARATION:
      buff->sym_table =
        ((struct parameter_declaration *) (buff->parent))->sym_table;
      break;

    case NODE_FUNCTION_DEFINITION:
      buff->sym_table =
        ((struct function_definition *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->ptr != NULL)
    buff->ptr->create_symtable (buff->ptr);
  if (buff->ddclr != NULL)
    buff->ddclr->create_symtable (buff->ddclr);
}

#if 0
symbol_t *
create_symbol_for_declarator (struct declarator *buff)
{
  assert (buff);
  assert (buff->kind == NODE_DECLARATOR);

  return create_symbol_for_direct_declarator (buff->ddclr);
}

int
create_symbols_for_parameters (struct declarator *buff, symbol_t *** sym_pars)
{
  assert (buff != NULL);
  assert (sym_pars != NULL);
  assert (buff->kind == NODE_DECLARATOR);

  return create_symbols_for_func_pars (buff->ddclr, sym_pars);
}

void
set_declarator_scope (struct declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATOR);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_INIT_DECLARATOR:
        set_init_declarator_scope (buff->parent);
        buff->scope = ((struct init_declarator *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct init_declarator *) (buff->parent))->scope_kind;
        break;

      case NODE_STRUCT_DECLARATOR:
        set_struct_declarator_scope (buff->parent);
        buff->scope = ((struct struct_declarator *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct struct_declarator *) (buff->parent))->scope_kind;
        break;

      case NODE_DIRECT_DECLARATOR:
        set_direct_declarator_scope (buff->parent);
        buff->scope = ((struct direct_declarator *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct direct_declarator *) (buff->parent))->scope_kind;
        break;

      case NODE_PARAMETER_DECLARATION:
        set_parameter_declaration_scope (buff->parent);
        buff->scope =
          ((struct parameter_declaration *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct parameter_declaration *) (buff->parent))->scope_kind;
        break;

      case NODE_FUNCTION_DEFINITION:
        buff->scope = ((struct function_definition *) (buff->parent))->parent;
        buff->scope_kind = NODE_TRANSLATION_UNIT;
        break;

      default:
        ;                       /* BUG! */
      }
}
#endif
