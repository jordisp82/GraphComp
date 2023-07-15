#include <assert.h>
#include <stdlib.h>

#include "enumerator.h"
#include "enumeration_constant.h"
#include "constant_expression.h"
#include "enumerator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void e_create_symtable (struct enumerator *buff);

struct enumerator *
enumerator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct enumerator *buff = calloc (1, sizeof (struct enumerator));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR;
  buff->e_kind = ENUM_WITH_CONST_EXPR;
  buff->ec = ptr1;
  buff->expr = ptr2;
  buff->ec->parent_kind = buff->expr->parent_kind = NODE_ENUMERATOR;
  buff->ec->parent = buff->expr->parent = buff;
  buff->create_symtable = e_create_symtable;

  return buff;
}

struct enumerator *
enumerator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct enumerator *buff = calloc (1, sizeof (struct enumerator));
  assert (buff != NULL);
  buff->kind = NODE_ENUMERATOR;
  buff->e_kind = ENUM_NO_CONST_EXPR;
  buff->ec = ptr;
  buff->ec->parent_kind = NODE_ENUMERATOR;
  buff->ec->parent = buff;
  buff->create_symtable = e_create_symtable;

  return buff;
}

static void
e_create_symtable (struct enumerator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATOR);

  buff->sym_table = ((struct enumerator_list *) (buff->parent))->sym_table;
  if (buff->ec != NULL)
    buff->ec->create_symtable (buff->ec);
  if (buff->expr != NULL)
    buff->expr->create_symtable (buff->expr);
}

#if 0
void
set_enumerator_scope (struct enumerator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ENUMERATOR);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_ENUMERATOR_LIST:
        set_enumerator_list_scope (buff->parent);
        buff->scope = ((struct enumerator_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct enumerator_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
#endif
