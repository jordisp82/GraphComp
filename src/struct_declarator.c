#include <assert.h>
#include <stdlib.h>

#include "struct_declarator.h"
#include "declarator.h"
#include "constant_expression.h"
#include "struct_declarator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct struct_declarator *
struct_declarator_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declarator *buff =
    calloc (1, sizeof (struct struct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATOR;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_STRUCT_DECLARATOR;
  buff->expr->parent = buff;

  return buff;
}

struct struct_declarator *
struct_declarator_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declarator *buff =
    calloc (1, sizeof (struct struct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATOR;
  buff->dclr = ptr1;
  buff->expr = ptr2;
  buff->dclr->parent_kind = buff->expr->parent_kind = NODE_STRUCT_DECLARATOR;
  buff->dclr->parent = buff->expr->parent = buff;

  return buff;
}

struct struct_declarator *
struct_declarator_3 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declarator *buff =
    calloc (1, sizeof (struct struct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATOR;
  buff->dclr = ptr;
  buff->dclr->parent_kind = NODE_STRUCT_DECLARATOR;
  buff->dclr->parent = buff;

  return buff;
}

void
set_struct_declarator_scope (struct struct_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_DECLARATOR);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_STRUCT_DECLARATOR_LIST:
        set_struct_declarator_list_scope (buff->parent);
        buff->scope =
          ((struct struct_declarator_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct struct_declarator_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
