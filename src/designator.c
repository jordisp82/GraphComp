#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "designator.h"
#include "constant_expression.h"
#include "designator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void d_create_symtable (struct designator *buff);

struct designator *
designator_1 (void *ptr)
{
  assert (ptr != NULL);

  struct designator *buff = calloc (1, sizeof (struct designator));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR;
  buff->d_kind = DESIGNATOR_ARRAY;
  buff->ex = ptr;
  buff->ex->parent_kind = NODE_DESIGNATOR;
  buff->ex->parent = buff;
  buff->create_symtable = d_create_symtable;

  return buff;
}

struct designator *
designator_2 (const char *str)
{
  assert (str != NULL);

  struct designator *buff = calloc (1, sizeof (struct designator));
  assert (buff != NULL);
  buff->kind = NODE_DESIGNATOR;
  buff->d_kind = DESIGNATOR_FIELD;
  buff->str = strdup (str);
  assert (buff->str != NULL);
  buff->create_symtable = d_create_symtable;

  return buff;
}

static void
d_create_symtable (struct designator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATOR);

  buff->sym_table = ((struct designator_list *) (buff->parent))->sym_table;
  if (buff->ex != NULL)
    buff->ex->create_symtable (buff->ex);
}

#if 0
void
set_designator_scope (struct designator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATOR);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_DESIGNATOR_LIST:
        set_designator_list_scope (buff->parent);
        buff->scope = ((struct designator_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct designator_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
set_symbol_for_designator (struct designator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DESIGNATOR);

  if (buff->d_kind == DESIGNATOR_ARRAY)
    set_symbol_for_constant_expression (buff->ex);
}
#endif
