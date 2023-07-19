#include <assert.h>
#include <stdlib.h>

#include "designator_list.h"
#include "designator.h"
#include "designation.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void dl_create_symtable (struct designator_list *buff);
static void dl_create_symbol (struct designator_list *buff);

struct designator_list *
designator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct designator_list *buff = calloc (1, sizeof (struct designator_list));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR_LIST;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds = ptr;
  buff->first->ds->parent_kind = NODE_DESIGNATOR_LIST;
  buff->first->ds->parent = buff;
  buff->create_symtable = dl_create_symtable;
  buff->create_symbol = dl_create_symbol;

  return buff;
}

struct designator_list *
designator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct designator_list *buff = ptr1;
  struct designator *ds = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds = ds;
  ds->parent_kind = NODE_DESIGNATOR_LIST;
  ds->parent = buff;
  buff->create_symtable = dl_create_symtable;
  buff->create_symbol = dl_create_symbol;

  return buff;
}

static void
dl_create_symtable (struct designator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATOR_LIST);

  switch (buff->parent_kind)
    {
    case NODE_DESIGNATOR_LIST:
      buff->sym_table =
        ((struct designator_list *) (buff->parent))->sym_table;
      break;

    case NODE_DESIGNATION:
      buff->sym_table = ((struct designation *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  for (struct ds_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->ds->create_symtable (ptr->ds);
}

static void
dl_create_symbol (struct designator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATOR_LIST);
  assert (buff->sym_table != NULL);

  for (struct ds_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->ds->create_symbol (ptr->ds);
}
