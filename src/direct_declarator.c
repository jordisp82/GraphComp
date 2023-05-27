#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "direct_declarator.h"
#include "declarator.h"
#include "type_qualifier_list.h"
#include "assignment_expression.h"
#include "parameter_type_list.h"
#include "identifier_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct direct_declarator *
direct_declarator_1 (const char *str)
{
  assert (str != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 1;
  buff->id = strdup (str);

  return buff;
}

struct direct_declarator *
direct_declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 2;
  buff->declr = ptr;
  buff->declr->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->declr->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_3 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 3;
  buff->ddeclr = ptr;
  buff->ddeclr->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_4 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 4;
  buff->ddeclr = ptr;
  buff->ddeclr->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_5 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 5;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->ddeclr->parent_kind = buff->tql->parent_kind =
    buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff->ass->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_6 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 6;
  buff->ddeclr = ptr1;
  buff->ass = ptr2;
  buff->ddeclr->parent_kind = buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->ass->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_7 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 7;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ddeclr->parent_kind = buff->tql->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_8 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 8;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->ddeclr->parent_kind = buff->tql->parent_kind =
    buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff->ass->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_9 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 9;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->ddeclr->parent_kind = buff->tql->parent_kind =
    buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff->ass->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_10 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 10;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ddeclr->parent_kind = buff->tql->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_11 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 11;
  buff->ddeclr = ptr1;
  buff->ass = ptr2;
  buff->ddeclr->parent_kind = buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->ass->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_12 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 12;
  buff->ddeclr = ptr1;
  buff->ptl = ptr2;
  buff->ddeclr->parent_kind = buff->ptl->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->ptl->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_13 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 13;
  buff->ddeclr = ptr;
  buff->ddeclr->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff;

  return buff;
}

struct direct_declarator *
direct_declarator_14 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 14;
  buff->ddeclr = ptr1;
  buff->il = ptr2;
  buff->ddeclr->parent_kind = buff->il->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->il->parent = buff;

  return buff;
}

symbol_t *
create_symbol_for_direct_declarator (struct direct_declarator *buff)
{
  assert (buff != NULL);

  if (buff->n_prod == 1)
    {
      symbol_t *sym = calloc (1, sizeof (symbol_t));
      assert (sym != NULL);
      sym->name = buff->id;
      return sym;
    }
  else if (buff->n_prod == 2)
    return create_symbol_for_declarator (buff->declr);
  else
    return create_symbol_for_direct_declarator (buff->ddeclr);
}

int
create_symbols_for_func_pars (struct direct_declarator *buff,
                              symbol_t ** sym_pars)
{
  assert (buff != NULL);
  assert (sym_pars != NULL);
  assert (buff->kind == NODE_DIRECT_DECLARATOR);

  if (buff->n_prod != 12)
    {
      *sym_pars = NULL;
      return 0;
    }

  return create_symbols_for_param_tlist (buff->ptl, sym_pars);
}
