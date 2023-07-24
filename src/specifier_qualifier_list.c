#include <assert.h>
#include <stdlib.h>

#include "specifier_qualifier_list.h"
#include "type_qualifier.h"
#include "type_specifier.h"
#include "struct_declaration.h"
#include "type_name.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sql_create_symtable (struct specifier_qualifier_list *buff);
static void sql_create_symbol (struct specifier_qualifier_list *buff);

struct specifier_qualifier_list *
specifier_qualifier_list_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct specifier_qualifier_list *buff = ptr1;
  struct type_specifier *ts = ptr2;

  buff->last->next = calloc (1, sizeof (struct sql_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->sq_kind = SQ_TYPE_SPEC;
  buff->last->ts = ts;
  ts->parent_kind = NODE_SPECIFIER_QUALIFIER_LIST;
  ts->parent = buff;
  buff->create_symtable = sql_create_symtable;
  buff->create_symbol = sql_create_symbol;

  return buff;
}

struct specifier_qualifier_list *
specifier_qualifier_list_2 (void *ptr)
{
  assert (ptr != NULL);

  struct specifier_qualifier_list *buff =
    calloc (1, sizeof (struct specifier_qualifier_list));
  assert (buff != NULL);
  buff->kind = NODE_SPECIFIER_QUALIFIER_LIST;
  buff->first = calloc (1, sizeof (struct sql_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->sq_kind = SQ_TYPE_SPEC;
  buff->first->ts = ptr;
  buff->first->ts->parent_kind = NODE_SPECIFIER_QUALIFIER_LIST;
  buff->first->ts->parent = buff;
  buff->create_symtable = sql_create_symtable;
  buff->create_symbol = sql_create_symbol;

  return buff;
}

struct specifier_qualifier_list *
specifier_qualifier_list_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct specifier_qualifier_list *buff = ptr1;
  struct type_qualifier *tq = ptr2;

  buff->last->next = calloc (1, sizeof (struct sql_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->sq_kind = SQ_TYPE_QUAL;
  buff->last->tq = tq;
  tq->parent_kind = NODE_SPECIFIER_QUALIFIER_LIST;
  tq->parent = buff;
  buff->create_symtable = sql_create_symtable;
  buff->create_symbol = sql_create_symbol;

  return buff;
}

struct specifier_qualifier_list *
specifier_qualifier_list_4 (void *ptr)
{
  assert (ptr != NULL);

  struct specifier_qualifier_list *buff =
    calloc (1, sizeof (struct specifier_qualifier_list));
  assert (buff != NULL);
  buff->kind = NODE_SPECIFIER_QUALIFIER_LIST;
  buff->first = calloc (1, sizeof (struct sql_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->sq_kind = SQ_TYPE_QUAL;
  buff->first->tq = ptr;
  buff->first->tq->parent_kind = NODE_SPECIFIER_QUALIFIER_LIST;
  buff->first->tq->parent = buff;
  buff->create_symtable = sql_create_symtable;
  buff->create_symbol = sql_create_symbol;

  return buff;
}

static void
sql_create_symtable (struct specifier_qualifier_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_SPECIFIER_QUALIFIER_LIST);

  switch (buff->parent_kind)
    {
    case NODE_SPECIFIER_QUALIFIER_LIST:
      buff->sym_table =
        ((struct specifier_qualifier_list *) (buff->parent))->sym_table;
      break;

    case NODE_STRUCT_DECLARATION:
      buff->sym_table =
        ((struct struct_declaration *) (buff->parent))->sym_table;
      break;

    case NODE_TYPE_NAME:
      buff->sym_table = ((struct type_name *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  for (struct sql_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->sq_kind)
      {
      case SQ_TYPE_SPEC:
        ptr->ts->create_symtable (ptr->ts);
        break;

      case SQ_TYPE_QUAL:
        ptr->tq->create_symtable (ptr->tq);
        break;

      default:
        ;                       /* BUG! */
      }
}

static void
sql_create_symbol (struct specifier_qualifier_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_SPECIFIER_QUALIFIER_LIST);
  assert (buff->sym_table != NULL);

  for (struct sql_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->sq_kind)
      {
      case SQ_TYPE_SPEC:
        ptr->ts->create_symbol (ptr->ts);
        break;

      case SQ_TYPE_QUAL:
        ptr->tq->create_symtable (ptr->tq);
        break;

      default:
        ;                       /* BUG! */
      }
}
