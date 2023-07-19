#include <assert.h>
#include <stdlib.h>

#include "parameter_type_list.h"
#include "parameter_list.h"
#include "direct_declarator.h"
#include "direct_abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ptl_create_symtable (struct parameter_type_list *buff);

struct parameter_type_list *
parameter_type_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_type_list *buff =
    calloc (1, sizeof (struct parameter_type_list));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_TYPE_LIST;
  buff->pl = ptr;
  buff->ellipsis = 1;
  buff->pl->parent_kind = NODE_PARAMETER_TYPE_LIST;
  buff->pl->parent = buff;
  buff->create_symtable = ptl_create_symtable;

  return buff;
}

struct parameter_type_list *
parameter_type_list_2 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_type_list *buff =
    calloc (1, sizeof (struct parameter_type_list));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_TYPE_LIST;
  buff->pl = ptr;
  buff->ellipsis = 0;
  buff->pl->parent_kind = NODE_PARAMETER_TYPE_LIST;
  buff->pl->parent = buff;
  buff->create_symtable = ptl_create_symtable;

  return buff;
}

static void
ptl_create_symtable (struct parameter_type_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_PARAMETER_TYPE_LIST);

  buff->sym_table = calloc (1, sizeof (struct symtable));
  assert (buff->sym_table != NULL);
  buff->sym_table->node = buff;
  buff->sym_table->node_kind = NODE_PARAMETER_TYPE_LIST;

  switch (buff->parent_kind)
    {
    case NODE_DIRECT_DECLARATOR:
      buff->sym_table->parent =
        ((struct direct_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_DIRECT_ABSTRACT_DECLARATOR:
      buff->sym_table->parent =
        ((struct direct_abstract_declarator *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  int n = buff->sym_table->parent->n_children;
  struct symtable **new_ch = calloc (n + 1, sizeof (struct symtable *));
  assert (new_ch != NULL);
  for (int i = 0; i < n; i++)
    new_ch[i] = buff->sym_table->parent->children[i];
  new_ch[n] = buff->sym_table;
  free (buff->sym_table->parent->children);
  buff->sym_table->parent->children = new_ch;
  buff->sym_table->parent->n_children++;

  if (buff->pl != NULL)
    buff->pl->create_symtable (buff->pl);
  buff->sym_table->ord = buff->sym_table->tags = NULL;
}
