#include <assert.h>
#include <stdlib.h>

#include "parameter_list.h"
#include "parameter_declaration.h"
#include "parameter_type_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct parameter_list *
parameter_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_list *buff = calloc (1, sizeof (struct parameter_list));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_LIST;
  buff->first = calloc (1, sizeof (struct pl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->pd = ptr;
  buff->first->pd->parent_kind = NODE_PARAMETER_LIST;
  buff->first->pd->parent = buff;

  return buff;
}

struct parameter_list *
parameter_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct parameter_list *buff = ptr1;
  struct parameter_declaration *pd = ptr2;

  buff->last->next = calloc (1, sizeof (struct pl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->pd = pd;
  pd->parent_kind = NODE_PARAMETER_LIST;
  pd->parent = buff;

  return buff;
}

int
create_symbols_for_param_list (struct parameter_list *buff,
                               symbol_t *** sym_pars)
{
  assert (buff != NULL);
  assert (sym_pars != NULL);
  assert (buff->kind == NODE_PARAMETER_LIST);

  int n = 0;
  struct pl_node *ptr;
  for (ptr = buff->first; ptr != NULL; n++, ptr = ptr->next);

  symbol_t **aux = calloc (n, sizeof (symbol_t *));
  assert (aux != NULL);

  int i = 0;
  for (ptr = buff->first; ptr != NULL; i++, ptr = ptr->next)
    aux[i] = create_symbol_for_param_declaration (ptr->pd);

  *sym_pars = aux;
  return n;
}

void
set_parameter_list (struct parameter_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PARAMETER_LIST);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_PARAMETER_LIST:
        set_parameter_list (buff->parent);
        buff->scope = ((struct parameter_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct parameter_list *) (buff->parent))->scope_kind;
        break;

      case NODE_PARAMETER_TYPE_LIST:
        set_parameter_type_list_scope (buff->parent);
        buff->scope = ((struct parameter_type_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct parameter_type_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
