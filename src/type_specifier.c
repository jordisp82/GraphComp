#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_specifier.h"
#include "atomic_type_specifier.h"
#include "struct_or_union_specifier.h"
#include "enum_specifier.h"
#include "declaration_specifiers.h"
#include "specifier_qualifier_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct type_specifier *
type_specifier_1 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_VOID;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_2 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_CHAR;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_3 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_SHORT;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_4 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_INT;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_5 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_LONG;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_6 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_FLOAT;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_7 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_DOUBLE;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_8 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_SIGNED;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_9 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_UNSIGNED;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_10 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_BOOL;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_11 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_COMPLEX;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_12 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_IMAGINARY;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_13 (void *ptr)
{
  assert (ptr != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_ATOMIC;
  buff->ats = ptr;
  buff->ats->parent_kind = NODE_TYPE_SPECIFIER;
  buff->ats->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_14 (void *ptr)
{
  assert (ptr != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_STRUCT_UNION;
  buff->sus = ptr;
  buff->sus->parent_kind = NODE_TYPE_SPECIFIER;
  buff->sus->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_15 (void *ptr)
{
  assert (ptr != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_ENUM;
  buff->es = ptr;
  buff->es->parent_kind = NODE_TYPE_SPECIFIER;
  buff->es->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_specifier *
type_specifier_16 (const char *str)
{
  assert (str != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_TYPEDEF;
  buff->typedef_name = strdup (str);
  assert (buff->typedef_name != NULL);

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct type_specifier *node = Node;
  assert (node->kind == NODE_TYPE_SPECIFIER);
  FILE *f = F;

  switch (node->ts_kind)
    {
    case TS_VOID:
      fprintf (f, "\t%lu [label=\"void\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_CHAR:
      fprintf (f, "\t%lu [label=\"char\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_SHORT:
      fprintf (f, "\t%lu [label=\"short\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_INT:
      fprintf (f, "\t%lu [label=\"int\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_LONG:
      fprintf (f, "\t%lu [label=\"long\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_FLOAT:
      fprintf (f, "\t%lu [label=\"float\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_DOUBLE:
      fprintf (f, "\t%lu [label=\"double\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_SIGNED:
      fprintf (f, "\t%lu [label=\"signed\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_UNSIGNED:
      fprintf (f, "\t%lu [label=\"unsigned\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_BOOL:
      fprintf (f, "\t%lu [label=\"_Bool\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_COMPLEX:
      fprintf (f, "\t%lu [label=\"_Complex\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TS_IMAGINARY:
      /* NOTE ??? */
      break;

    case TS_ATOMIC:
      /* todo */ break;

    case TS_STRUCT_UNION:
      /* todo */ break;

    case TS_ENUM:
      /* todo */ break;

    case TS_TYPEDEF:
      /* todo */ break;

    default:;                  /* BUG! */
    }
}
