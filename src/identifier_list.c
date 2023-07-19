#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "identifier_list.h"
#include "direct_declarator.h"
#include "identifier_list.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void il_create_symtable (struct identifier_list *buff);
static void il_create_symbol (struct identifier_list *buff);

struct identifier_list *
identifier_list_1 (const char *str)
{
  assert (str != NULL);

  struct identifier_list *buff = calloc (1, sizeof (struct identifier_list));
  assert (buff != NULL);
  buff->kind = NODE_IDENTIFIER_LIST;
  buff->first = calloc (1, sizeof (struct il_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->str = strdup (str);
  assert (buff->first->str != NULL);
  buff->create_symtable = il_create_symtable;
  buff->create_symbol = il_create_symbol;

  return buff;
}

struct identifier_list *
identifier_list_2 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct identifier_list *buff = ptr1;
  buff->last->next = calloc (1, sizeof (struct il_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->str = strdup (str);
  assert (buff->last->str != NULL);
  buff->create_symtable = il_create_symtable;
  buff->create_symbol = il_create_symbol;

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

static void
il_create_symbol (struct identifier_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_IDENTIFIER_LIST);
  assert (buff->sym_table != NULL);

  for (struct il_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    {
      avl_node_t *node = avl_search (buff->sym_table->ord, ptr->str);
      if (node != NULL)
        ptr->sym = node->value;
    }
}
