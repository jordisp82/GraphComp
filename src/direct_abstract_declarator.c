#include <assert.h>
#include <stdlib.h>

#include "direct_abstract_declarator.h"
#include "abstract_declarator.h"
#include "type_qualifier_list.h"
#include "assignment_expression.h"
#include "parameter_type_list.h"
#include "abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void dad_create_symtable (struct direct_abstract_declarator *buff);

struct direct_abstract_declarator *
direct_abstract_declarator_1 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 1;
  buff->adclr = ptr;
  buff->adclr->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->adclr->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_2 (void)
{
  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 2;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_3 (void)
{
  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 3;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 4;
  buff->tql = ptr1;
  buff->ass = ptr2;
  buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->tql->parent = buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_5 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 5;
  buff->ass = ptr;
  buff->ass->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_6 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 6;
  buff->tql = ptr1;
  buff->ass = ptr2;
  buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->tql->parent = buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_7 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 7;
  buff->tql = ptr1;
  buff->ass = ptr2;
  buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->tql->parent = buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_8 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 8;
  buff->tql = ptr;
  buff->tql->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->tql->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_9 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 9;
  buff->ass = ptr;
  buff->ass->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_10 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 10;
  buff->dad = ptr;
  buff->dad->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_11 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 11;
  buff->dad = ptr;
  buff->dad->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_12 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 12;
  buff->dad = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->dad->parent_kind = buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->tql->parent = buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_13 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 13;
  buff->dad = ptr1;
  buff->ass = ptr2;
  buff->dad->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_14 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 14;
  buff->dad = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->dad->parent_kind = buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->tql->parent = buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_15 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 15;
  buff->dad = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->dad->parent_kind = buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->tql->parent = buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_16 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 16;
  buff->dad = ptr1;
  buff->tql = ptr2;
  buff->dad->parent_kind = buff->tql->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->tql->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_17 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 17;
  buff->dad = ptr1;
  buff->ass = ptr2;
  buff->dad->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->ass->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_18 (void)
{
  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 18;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_19 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 19;
  buff->ptl = ptr;
  buff->ptl->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->ptl->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_20 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 20;
  buff->dad = ptr;
  buff->dad->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_21 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 21;
  buff->dad = ptr1;
  buff->ptl = ptr2;
  buff->dad->parent_kind = buff->ptl->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->ptl->parent = buff;
  buff->create_symtable = dad_create_symtable;

  return buff;
}

static void
dad_create_symtable (struct direct_abstract_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DIRECT_ABSTRACT_DECLARATOR);

  switch (buff->parent_kind)
    {
    case NODE_ABSTRACT_DECLARATOR:
      buff->sym_table =
        ((struct abstract_declarator *) (buff->parent))->sym_table;
      break;

    case NODE_DIRECT_ABSTRACT_DECLARATOR:
      buff->sym_table =
        ((struct direct_abstract_declarator *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->adclr != NULL)
    buff->adclr->create_symtable (buff->adclr);
  if (buff->tql != NULL)
    buff->tql->create_symtable (buff->tql);
  if (buff->ass != NULL)
    buff->ass->create_symtable (buff->ass);
  if (buff->ptl != NULL)
    buff->ptl->create_symtable (buff->ptl);
  if (buff->dad != NULL)
    buff->dad->create_symtable (buff->dad);
}

#if 0
void
set_direct_abs_declarator_scope (struct direct_abstract_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DIRECT_ABSTRACT_DECLARATOR);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_ABSTRACT_DECLARATOR:
        set_abstract_declarator_scope (buff->parent);
        buff->scope = ((struct abstract_declarator *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct abstract_declarator *) (buff->parent))->scope_kind;
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
#endif
