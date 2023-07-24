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

static void ad_create_symtable (struct abstract_declarator *buff);
static void ad_create_symbol (struct abstract_declarator *buff);

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
  buff->create_symtable = ad_create_symtable;
  buff->create_symbol = ad_create_symbol;

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
  buff->create_symtable = ad_create_symtable;
  buff->create_symbol = ad_create_symbol;

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
  buff->create_symtable = ad_create_symtable;
  buff->create_symbol = ad_create_symbol;

  return buff;
}

static void
ad_create_symtable (struct abstract_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ABSTRACT_DECLARATOR);

  switch (buff->parent_kind)
    {
    case NODE_PARAMETER_DECLARATION:
      buff->sym_table =
        ((struct parameter_declaration *) (buff->parent))->sym_table;
      break;

    case NODE_TYPE_NAME:
      buff->sym_table = ((struct type_name *) (buff->parent))->sym_table;
      break;

    case NODE_DIRECT_ABSTRACT_DECLARATOR:
      buff->sym_table =
        ((struct direct_abstract_declarator *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->ptr != NULL)
    buff->ptr->create_symtable (buff->ptr);
  if (buff->dad != NULL)
    buff->dad->create_symtable (buff->dad);
}

static void
ad_create_symbol (struct abstract_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ABSTRACT_DECLARATOR);
  assert (buff->sym_table != NULL);

  if (buff->dad != NULL)
    buff->dad->create_symbol (buff->dad);
}
