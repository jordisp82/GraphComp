#include <assert.h>
#include <stdlib.h>

#include "specifier_qualifier_list.h"
#include "type_qualifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

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
#if 0
  ts->parent_kind = NODE_SPECIFIER_QUALIFIER_LIST;
  ts->parent = buff;
#endif

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
#if 0
  buff->first->ts->parent_kind = NODE_SPECIFIER_QUALIFIER_LIST;
  buff->first->ts->parent = buff;
#endif

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

  return buff;
}
