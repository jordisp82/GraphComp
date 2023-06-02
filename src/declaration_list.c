#include <assert.h>
#include <stdlib.h>

#include "declaration_list.h"
#include "declaration.h"
#include "function_definition.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct declaration_list *
declaration_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_list *buff =
    calloc (1, sizeof (struct declaration_list));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_LIST;
  buff->first = calloc (1, sizeof (struct dl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->dl = ptr;
  buff->first->dl->parent_kind = NODE_DECLARATION_LIST;
  buff->first->dl->parent = buff;

  return buff;
}

struct declaration_list *
declaration_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declaration_list *buff = ptr1;
  struct declaration *dl = ptr2;

  buff->last->next = calloc (1, sizeof (struct dl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->dl = dl;
  dl->parent_kind = NODE_DECLARATION_LIST;
  dl->parent = buff;

  return buff;
}

void
set_declaration_list_scope (struct declaration_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION_LIST);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_FUNCTION_DEFINITION:
        buff->scope = ((struct function_definition *) (buff->parent))->parent;
        buff->scope_kind = NODE_TRANSLATION_UNIT;
        break;

      default:
        ;                       /* BUG! */
      }
}
