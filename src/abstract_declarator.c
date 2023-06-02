#include <assert.h>
#include <stdlib.h>

#include "abstract_declarator.h"
#include "pointer.h"
#include "direct_abstract_declarator.h"
#include "parameter_declaration.h"
#include "type_name.h"
#include "direct_abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct abstract_declarator *
abstract_declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct abstract_declarator *buff =
    calloc (1, sizeof (struct abstract_declarator));
  assert (buff != NULL);
  buff->kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr = ptr1;
  buff->dad = ptr2;
  buff->ptr->parent_kind = buff->dad->parent_kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr->parent = buff->dad->parent = buff;

  return buff;
}

struct abstract_declarator *
abstract_declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct abstract_declarator *buff =
    calloc (1, sizeof (struct abstract_declarator));
  assert (buff != NULL);
  buff->kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr = ptr;
  buff->ptr->parent_kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr->parent = buff;

  return buff;
}

struct abstract_declarator *
abstract_declarator_3 (void *ptr)
{
  assert (ptr != NULL);

  struct abstract_declarator *buff =
    calloc (1, sizeof (struct abstract_declarator));
  assert (buff != NULL);
  buff->kind = NODE_ABSTRACT_DECLARATOR;
  buff->dad = ptr;
  buff->dad->parent_kind = NODE_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff;

  return buff;
}

void
set_abstract_declarator_scope (struct abstract_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ABSTRACT_DECLARATOR);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_PARAMETER_DECLARATION:
        set_parameter_declaration_scope (buff->parent);
        buff->scope =
          ((struct parameter_declaration *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct parameter_declaration *) (buff->parent))->scope_kind;
        break;

      case NODE_TYPE_NAME:
        set_type_name_scope (buff->parent);
        buff->scope = ((struct type_name *) (buff->parent))->scope;
        buff->scope_kind = ((struct type_name *) (buff->parent))->scope_kind;
        break;

      case NODE_DIRECT_ABSTRACT_DECLARATOR:
        set_direct_abs_declarator_scope (buff->parent);
        buff->scope =
          ((struct direct_abstract_declarator *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct direct_abstract_declarator *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
