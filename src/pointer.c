#include <assert.h>
#include <stdlib.h>

#include "pointer.h"
#include "type_qualifier_list.h"
#include "declarator.h"
#include "abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void p_create_symtable (struct pointer *buff);

struct pointer *
pointer_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_TQ_PTR;
  buff->tql = ptr1;
  buff->ptr = ptr2;
  buff->tql->parent_kind = buff->ptr->parent_kind = NODE_POINTER;
  buff->tql->parent = buff->ptr->parent = buff;
  buff->create_symtable = p_create_symtable;

  return buff;
}

struct pointer *
pointer_2 (void *ptr)
{
  assert (ptr != NULL);

  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_TQ;
  buff->tql = ptr;
  buff->tql->parent_kind = NODE_POINTER;
  buff->tql->parent = buff;
  buff->create_symtable = p_create_symtable;

  return buff;
}

struct pointer *
pointer_3 (void *ptr)
{
  assert (ptr != NULL);

  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_PTR;
  buff->ptr = ptr;
  buff->ptr->parent_kind = NODE_POINTER;
  buff->ptr->parent = buff;
  buff->create_symtable = p_create_symtable;

  return buff;
}

struct pointer *
pointer_4 (void)
{
  struct pointer *buff = calloc (1, sizeof (struct pointer));
  assert (buff != NULL);
  buff->kind = NODE_POINTER;
  buff->ptr_kind = PTR_EMPTY;
  buff->create_symtable = p_create_symtable;

  return buff;
}

static void
p_create_symtable (struct pointer *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_POINTER);

  switch (buff->parent_kind)
    {
    case NODE_POINTER:
      buff->sym_table = ((struct pointer *) (buff->parent))->sym_table;
      break;

    case NODE_DECLARATOR:
      buff->sym_table = ((struct declarator *) (buff->parent))->sym_table;
      break;

    case NODE_ABSTRACT_DECLARATOR:
      buff->sym_table =
        ((struct abstract_declarator *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->tql != NULL)
    buff->tql->create_symtable (buff->tql);
  if (buff->ptr != NULL)
    buff->ptr->create_symtable (buff->ptr);
}
