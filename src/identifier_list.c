#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "identifier_list.h"
#include "direct_declarator.h"
#include "identifier_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void il_create_symtable (struct identifier_list *buff);

struct identifier_list *
identifier_list_1 (const char *str)
{
  assert (str != NULL);

  struct identifier_list *buff = calloc (1, sizeof (struct identifier_list));
  assert (buff != NULL);
  buff->kind = NODE_IDENTIFIER_LIST;
  buff->first = calloc (1, sizeof (struct idl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->str = strdup (str);
  assert (buff->first->str != NULL);
  buff->create_symtable = il_create_symtable;

  return buff;
}

struct identifier_list *
identifier_list_2 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct identifier_list *buff = ptr1;
  buff->last->next = calloc (1, sizeof (struct idl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->str = strdup (str);
  assert (buff->last->str != NULL);
  buff->create_symtable = il_create_symtable;

  return buff;
}

static void
il_create_symtable (struct identifier_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_IDENTIFIER_LIST);

  switch (buff->parent_kind)
    {
    case NODE_DIRECT_DECLARATOR:
      buff->sym_table =
        ((struct direct_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_IDENTIFIER_LIST:
      buff->sym_table =
        ((struct identifier_list *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }
}
