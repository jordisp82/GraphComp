#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "direct_declarator.h"
#include "declarator.h"
#include "type_qualifier_list.h"
#include "assignment_expression.h"
#include "parameter_type_list.h"
#include "identifier_list.h"
#include "declaration.h"
#include "init_declarator.h"
#include "init_declarator_list.h"
#include "declaration_specifiers.h"
#include "storage_class_specifier.h"
#include "symbol.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void dd_create_symtable (struct direct_declarator *buff);
static void add_dd_to_symtable (struct direct_declarator *buff);
static void dd_create_symbol (struct direct_declarator *buff);

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

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
  buff->create_symtable = dd_create_symtable;
  buff->create_symbol = dd_create_symbol;

  return buff;
}

static void
dd_create_symtable (struct direct_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DIRECT_DECLARATOR);

  switch (buff->parent_kind)
    {
    case NODE_DECLARATOR:
      buff->sym_table = ((struct declarator *) (buff->parent))->sym_table;
      break;

    case NODE_DIRECT_DECLARATOR:
      buff->sym_table =
        ((struct direct_declarator *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->n_prod == 1)
    add_dd_to_symtable (buff);
  else
    {
      if (buff->declr != NULL)
        buff->declr->create_symtable (buff->declr);
      if (buff->ddeclr != NULL)
        buff->ddeclr->create_symtable (buff->ddeclr);
      if (buff->tql != NULL)
        buff->tql->create_symtable (buff->tql);
      if (buff->ass != NULL)
        buff->ass->create_symtable (buff->ass);
      if (buff->ptl != NULL)
        buff->ptl->create_symtable (buff->ptl);
      if (buff->il != NULL)
        buff->il->create_symtable (buff->il);
    }
}

static void
add_dd_to_symtable (struct direct_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DIRECT_DECLARATOR);
  assert (buff->n_prod == 1);
  assert (buff->id != NULL);

  /*
   * If the direct declarator belongs
   * to a struct or union, there is
   * nothing to be done.
   */

  /*
   * The parent of a direct-declarator is
   * either a declarator or another direct-declarator.
   * A declarator parent may be an init-declarator,
   * a struct-declarator, a direct-declarator, a
   * parameter-declarator, or a function definition.
   * In the case of a direct-declarator, we must look
   * upwards again. In the case of a struct-declarator,
   * we return. In the other cases, we proceed forward.
   */

  struct direct_declarator *aux1 = buff;
  struct declarator *aux2 = NULL;
  do
    {
      for (; aux1->parent_kind == NODE_DIRECT_DECLARATOR;
           aux1 = aux1->parent);
      /* the parent must be a declarator */
      aux2 = aux1->parent;
      /* but if its parent is a direct-declarator... */
      if (aux2->parent_kind != NODE_DIRECT_DECLARATOR)
        break;
    }
  while (1);

  /* here, aux2 points to a declarator whose parent
   * is not a direct declarator. */

  if (aux2->parent_kind == NODE_STRUCT_DECLARATOR)
    return;

  /* ok, now we can create the symbol and add it */
  symbol_t *sym = calloc (1, sizeof (symbol_t));
  assert (sym != NULL);
  sym->name = strdup (buff->id);
  assert (sym->name != NULL);
  sym->node = aux2;             /* NOTE potser estem apuntant massa amunt... */
  sym->node_kind = NODE_DECLARATOR;
  sym->sym_ns = SYM_NS_ORDINARY;
  buff->sym_table->ord = avl_add_create (buff->sym_table->ord, sym);
  /* NOTE remember that typedefs belong to the ordinary namespace */
}

static void
dd_create_symbol (struct direct_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DIRECT_DECLARATOR);
  assert (buff->sym_table != NULL);

  if (buff->n_prod == 14)
    buff->il->create_symbol (buff->il);
}
