#include <assert.h>
#include <stdlib.h>
//#include <stdio.h>              // temp!

#include "translation_unit.h"
#include "external_declaration.h"
#include "function_definition.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void tu_create_symtable (struct translation_unit *buff);
static void tu_create_symbol (struct translation_unit *buff);

struct translation_unit *
translation_unit_1 (void *ptr)
{
  assert (ptr != NULL);

  struct translation_unit *buff =
    calloc (1, sizeof (struct translation_unit));
  assert (buff != NULL);
  buff->kind = NODE_TRANSLATION_UNIT;
  buff->first = calloc (1, sizeof (struct tu_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ed = ptr;
  buff->first->ed->parent = buff;
  buff->first->ed->parent_kind = NODE_TRANSLATION_UNIT;
  buff->create_symtable = tu_create_symtable;
  buff->create_symbol = tu_create_symbol;

  return buff;
}

struct translation_unit *
translation_unit_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct translation_unit *buff = ptr1;
  struct external_declaration *ed = ptr2;

  buff->last->next = calloc (1, sizeof (struct tu_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ed = ed;
  ed->parent = buff;
  ed->parent_kind = NODE_TRANSLATION_UNIT;
  buff->create_symtable = tu_create_symtable;
  buff->create_symbol = tu_create_symbol;

  return buff;
}

static void
tu_create_symtable (struct translation_unit *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TRANSLATION_UNIT);

  buff->sym_table = calloc (1, sizeof (struct symtable));
  assert (buff->sym_table != NULL);
  buff->sym_table->parent = NULL;
  buff->sym_table->node = buff;
  buff->sym_table->node_kind = NODE_TRANSLATION_UNIT;
  buff->sym_table->n_children = 0;
  for (struct tu_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->ed->create_symtable (ptr->ed);
  buff->sym_table->ord = buff->sym_table->tags = NULL;
}

static void
tu_create_symbol (struct translation_unit *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TRANSLATION_UNIT);
  assert (buff->sym_table != NULL);
  for (struct tu_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->ed->create_symbol (ptr->ed);
}
