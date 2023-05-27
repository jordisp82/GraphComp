#include <assert.h>
#include <stdlib.h>

#include "parameter_list.h"
#include "parameter_declaration.h"

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
                               symbol_t ** sym_pars)
{
  assert (buff != NULL);
  assert (sym_pars != NULL);
  assert (buff->kind == NODE_PARAMETER_LIST);

  int n = 0;
  struct pl_node *ptr;
  for (ptr = buff->first; ptr != NULL; n++, ptr = ptr->next);

  *sym_pars = calloc (n, sizeof (symbol_t *));
  assert (sym_pars != NULL);

  int i = 0;
  for (ptr = buff->first; ptr != NULL; i++, ptr = ptr->next)
    sym_pars[i] = create_symbol_for_param_declaration (ptr->pd);

  return n;
}
