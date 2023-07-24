#include <assert.h>
#include <stdlib.h>

#include "struct_declarator.h"
#include "declarator.h"
#include "constant_expression.h"
#include "struct_declarator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sd_create_symtable (struct struct_declarator *buff);
static void sd_create_symbol (struct struct_declarator *buff);

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
  buff->create_symtable = sd_create_symtable;
  buff->create_symbol = sd_create_symbol;

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
  buff->create_symtable = sd_create_symtable;
  buff->create_symbol = sd_create_symbol;

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
  buff->create_symtable = sd_create_symtable;
  buff->create_symbol = sd_create_symbol;

  return buff;
}

static void
sd_create_symtable (struct struct_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_DECLARATOR);

  buff->sym_table =
    ((struct struct_declarator_list *) (buff->parent))->sym_table;
  if (buff->expr != NULL)
    buff->expr->create_symtable (buff->expr);
  if (buff->dclr != NULL)
    buff->dclr->create_symtable (buff->dclr);
}

static void
sd_create_symbol (struct struct_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_DECLARATOR);
  assert (buff->sym_table != NULL);

  if (buff->expr != NULL)
    buff->expr->create_symbol (buff->expr);
  if (buff->dclr != NULL)
    buff->dclr->create_symbol (buff->dclr);
}
