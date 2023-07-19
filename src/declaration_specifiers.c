#include <assert.h>
#include <stdlib.h>

#include "declaration_specifiers.h"
#include "storage_class_specifier.h"
#include "type_qualifier.h"
#include "function_specifier.h"
#include "alignment_specifier.h"
#include "type_specifier.h"
#include "declaration.h"
#include "parameter_declaration.h"
#include "function_definition.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ds_create_symtable (struct declaration_specifiers *buff);
static void ds_create_symbol (struct declaration_specifiers *buff);

struct declaration_specifiers *
declaration_specifiers_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct storage_class_specifier *stg = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->last->stg = stg;
  stg->parent_kind = NODE_DECLARATION_SPECIFIERS;
  stg->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_2 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->first->stg = ptr;
  buff->first->stg->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->stg->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_specifier *ts = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_TYPE_SPECIFIER;
  buff->last->ts = ts;
  ts->parent_kind = NODE_DECLARATION_SPECIFIERS;
  ts->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_4 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_TYPE_SPECIFIER;
  buff->first->ts = ptr;
  buff->first->ts->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->ts->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_5 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_qualifier *tq = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_TYPE_QUALIFIER;
  buff->last->tq = tq;
  tq->parent_kind = NODE_DECLARATION_SPECIFIERS;
  tq->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_6 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_TYPE_QUALIFIER;
  buff->first->tq = ptr;
  buff->first->tq->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->tq->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_7 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct function_specifier *fs = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_FUNCTION_SPECIFIER;
  buff->last->fs = fs;
  fs->parent_kind = NODE_DECLARATION_SPECIFIERS;
  fs->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_8 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_FUNCTION_SPECIFIER;
  buff->first->fs = ptr;
  buff->first->fs->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->fs->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_9 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct alignment_specifier *as = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->last->as = as;
  as->parent_kind = NODE_DECLARATION_SPECIFIERS;
  as->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_10 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->first->as = ptr;
  buff->first->as->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->as->parent = buff;
  buff->create_symtable = ds_create_symtable;
  buff->create_symbol = ds_create_symbol;

  return buff;
}

static void
ds_create_symtable (struct declaration_specifiers *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION_SPECIFIERS);

  switch (buff->parent_kind)
    {
    case NODE_DECLARATION:
      buff->sym_table = ((struct declaration *) (buff->parent))->sym_table;
      break;

    case NODE_PARAMETER_DECLARATION:
      buff->sym_table =
        ((struct parameter_declaration *) (buff->parent))->sym_table;
      break;

    case NODE_FUNCTION_DEFINITION:
      buff->sym_table =
        ((struct function_definition *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  for (struct ds_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_STORAGE_CLASS_SPECIFIER:
        ptr->stg->create_symtable (ptr->stg);
        break;

      case NODE_TYPE_SPECIFIER:
        ptr->ts->create_symtable (ptr->ts);
        break;

      case NODE_TYPE_QUALIFIER:
        ptr->tq->create_symtable (ptr->tq);
        break;

      case NODE_FUNCTION_SPECIFIER:
        ptr->fs->create_symtable (ptr->fs);
        break;

      case NODE_ALIGNMENT_SPECIFIER:
        ptr->as->create_symtable (ptr->as);
        break;

      default:
        ;                       /* BUG! */
      }
}

static void
ds_create_symbol (struct declaration_specifiers *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION_SPECIFIERS);
  assert (buff->sym_table != NULL);

  for (struct ds_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_STORAGE_CLASS_SPECIFIER:
        ptr->stg->create_symbol (ptr->stg);
        break;

      case NODE_TYPE_SPECIFIER:
        ptr->ts->create_symbol (ptr->ts);
        break;

      case NODE_TYPE_QUALIFIER:
        ptr->tq->create_symbol (ptr->tq);
        break;

      case NODE_FUNCTION_SPECIFIER:
        ptr->fs->create_symbol (ptr->fs);
        break;

      case NODE_ALIGNMENT_SPECIFIER:
        ptr->as->create_symbol (ptr->as);
        break;

      default:
        ;                       /* BUG! */
      }
}

int
is_there_typedef (struct declaration_specifiers *buff)
{
  assert (buff != NULL);

  for (struct ds_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    if (ptr->ds_kind == NODE_STORAGE_CLASS_SPECIFIER)
      if (ptr->stg->value == STG_TYPEDEF)
        return 1;

  return 0;
}
