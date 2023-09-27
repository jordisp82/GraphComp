#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
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

static void local_dot_create (void *Node, void *F);

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

  return buff;
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

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct declaration_specifiers *node = Node;
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);
  FILE *f = F;

  for (struct ds_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_STORAGE_CLASS_SPECIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->stg);
        fprintf (f, "\t%lu [label=\"storage class specifier\"]\n",
                 (unsigned long) ptr->stg);
        ptr->stg->dot_create (ptr->stg, f);
        break;

      case NODE_TYPE_SPECIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->ts);
        fprintf (f, "\t%lu [label=\"type specifier\"]\n",
                 (unsigned long) ptr->ts);
        ptr->ts->dot_create (ptr->ts, f);
        break;

      case NODE_TYPE_QUALIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->tq);
        fprintf (f, "\t%lu [label=\"type qualifier\"]\n",
                 (unsigned long) ptr->tq);
        ptr->tq->dot_create (ptr->tq, f);
        break;

      case NODE_FUNCTION_SPECIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->fs);
        fprintf (f, "\t%lu [label=\"function specifier\"]\n",
                 (unsigned long) ptr->fs);
        ptr->fs->dot_create (ptr->fs, f);
        break;

      case NODE_ALIGNMENT_SPECIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->as);
        fprintf (f, "\t%lu [label=\"alignment specifier\"]\n",
                 (unsigned long) ptr->as);
        ptr->as->dot_create (ptr->as, f);
        break;

      default:;                /* BUG! */
      }
}
