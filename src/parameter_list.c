#include <assert.h>
#include <stdlib.h>

#include "parameter_list.h"
#include "parameter_declaration.h"
#include "parameter_type_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void pl_create_symtable (struct parameter_list *buff);
static void pl_create_symbol (struct parameter_list *buff);

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
  buff->create_symtable = pl_create_symtable;
  buff->create_symbol = pl_create_symbol;

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
  buff->create_symtable = pl_create_symtable;
  buff->create_symbol = pl_create_symbol;

  return buff;
}

static void
pl_create_symtable (struct parameter_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PARAMETER_LIST);

  switch (buff->parent_kind)
    {
    case NODE_PARAMETER_LIST:
      buff->sym_table = ((struct parameter_list *) (buff->parent))->sym_table;
      break;

    case NODE_PARAMETER_TYPE_LIST:
      buff->sym_table =
        ((struct parameter_type_list *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  for (struct pl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->pd->create_symtable (ptr->pd);
}

static void
pl_create_symbol (struct parameter_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PARAMETER_LIST);
  assert (buff->sym_table != NULL);

  for (struct pl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->pd->create_symbol (ptr->pd);
}
