#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "specifier_qualifier_list.h"
#include "type_qualifier.h"
#include "type_specifier.h"
#include "struct_declaration.h"
#include "type_name.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct specifier_qualifier_list *node = Node;
  assert (node->kind == NODE_SPECIFIER_QUALIFIER_LIST);
  FILE *f = F;

  for (struct sql_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->sq_kind)
      {
      case SQ_TYPE_SPEC:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->ts);
        fprintf (f, "\t%lu [label=\"type specifier\"]\n",
                 (unsigned long) ptr->ts);
        ptr->ts->dot_create (ptr->ts, f);
        break;

      case SQ_TYPE_QUAL:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->tq);
        fprintf (f, "\t%lu [label=\"type qualifier\"]\n",
                 (unsigned long) ptr->tq);
        ptr->tq->dot_create (ptr->tq, f);
        break;

      default:;                /* BUG! */
      }
}
