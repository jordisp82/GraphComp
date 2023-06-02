#include <assert.h>
#include <stdlib.h>

#include "enumerator_list.h"
#include "enumerator.h"
#include "enum_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct enumerator_list *
enumerator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct enumerator_list *buff = calloc (1, sizeof (struct enumerator_list));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR_LIST;
  buff->first = calloc (1, sizeof (struct enl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->en = ptr;
  buff->first->en->parent_kind = NODE_ENUMERATOR_LIST;
  buff->first->en->parent = buff;

  return buff;
}

struct enumerator_list *
enumerator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct enumerator_list *buff = ptr1;
  struct enumerator *en = ptr2;

  buff->last->next = calloc (1, sizeof (struct enl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->en = en;
  en->parent_kind = NODE_ENUMERATOR_LIST;
  en->parent = buff;

  return buff;
}

void
set_enumerator_list_scope (struct enumerator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATOR_LIST);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_ENUMERATOR_LIST:
        set_enumerator_list_scope (buff->parent);
        buff->scope = ((struct enumerator_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct enumerator_list *) (buff->parent))->scope_kind;
        break;

      case NODE_ENUM_SPECIFIER:
        set_enum_specifier_scope (buff->parent);
        buff->scope = ((struct enum_specifier *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct enum_specifier *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
