#include <assert.h>
#include <stdlib.h>

#include "parameter_declaration.h"
#include "declaration_specifiers.h"
#include "declarator.h"
#include "abstract_declarator.h"
#include "parameter_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void pd_create_symtable (struct parameter_declaration *buff);

struct parameter_declaration *
parameter_declaration_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct parameter_declaration *buff =
    calloc (1, sizeof (struct parameter_declaration));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_DECLARATION;
  buff->pd_kind = PD_DS_DECLR;
  buff->ds = ptr1;
  buff->dr = ptr2;
  buff->ds->parent_kind = buff->dr->parent_kind = NODE_PARAMETER_DECLARATION;
  buff->ds->parent = buff->dr->parent = buff;
  buff->create_symtable = pd_create_symtable;

  return buff;
}

struct parameter_declaration *
parameter_declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct parameter_declaration *buff =
    calloc (1, sizeof (struct parameter_declaration));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_DECLARATION;
  buff->pd_kind = PD_DS_ABS_DECLR;
  buff->ds = ptr1;
  buff->adr = ptr2;
  buff->ds->parent_kind = buff->adr->parent_kind = NODE_PARAMETER_DECLARATION;
  buff->ds->parent = buff->adr->parent = buff;
  buff->create_symtable = pd_create_symtable;

  return buff;
}

struct parameter_declaration *
parameter_declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_declaration *buff =
    calloc (1, sizeof (struct parameter_declaration));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_DECLARATION;
  buff->pd_kind = PD_DS;
  buff->ds = ptr;
  buff->ds->parent_kind = NODE_PARAMETER_DECLARATION;
  buff->ds->parent = buff;
  buff->create_symtable = pd_create_symtable;

  return buff;
}

static void
pd_create_symtable (struct parameter_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PARAMETER_DECLARATION);

  buff->sym_table = ((struct parameter_list *) (buff->parent))->sym_table;
  if (buff->ds != NULL)
    buff->ds->create_symtable (buff->ds);
  switch (buff->pd_kind)
    {
    case PD_DS_DECLR:
      buff->dr->create_symtable (buff->dr);
      break;

    case PD_DS_ABS_DECLR:
      buff->adr->create_symtable (buff->adr);
      break;

    case PD_DS:
      break;

    default:
      ;                         /* BUG! */
    }
}

#if 0
symbol_t *
create_symbol_for_param_declaration (struct parameter_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PARAMETER_DECLARATION);

  /*
   * Since this function is used to create
   * a symbol table, we're not interested in
   * abstract declarators.
   */

  if (buff->pd_kind != PD_DS_DECLR)
    return NULL;

  symbol_t *sym = create_symbol_for_declarator (buff->dr);
  sym->dclr = buff->dr;
  sym->sym_ns = SYM_NS_ORDINARY;
  return sym;
}

void
set_parameter_declaration_scope (struct parameter_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PARAMETER_DECLARATION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_PARAMETER_LIST:
        set_parameter_list_scope (buff->parent);
        buff->scope = ((struct parameter_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct parameter_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
#endif
