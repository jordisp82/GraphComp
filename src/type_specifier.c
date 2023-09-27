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
static void do_term (struct type_specifier *node, FILE * f,
                     const char *token, int n_token);

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
      do_term (node, f, "void", 0);
      break;

    case TS_CHAR:
      do_term (node, f, "char", 0);
      break;

    case TS_SHORT:
      do_term (node, f, "short", 0);
      break;

    case TS_INT:
      do_term (node, f, "int", 0);
      break;

    case TS_LONG:
      do_term (node, f, "long", 0);
      break;

    case TS_FLOAT:
      do_term (node, f, "float", 0);
      break;

    case TS_DOUBLE:
      do_term (node, f, "double", 0);
      break;

    case TS_SIGNED:
      do_term (node, f, "signed", 0);
      break;

    case TS_UNSIGNED:
      do_term (node, f, "unsigned", 0);
      break;

    case TS_BOOL:
      do_term (node, f, "_Bool", 0);
      break;

    case TS_COMPLEX:
      do_term (node, f, "_Complex", 0);
      break;

    case TS_IMAGINARY:
      /* NOTE ??? */
      break;

    case TS_ATOMIC:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ats);
      fprintf (f, "\t%lu [label=\"atomic type specifier\"]\n",
               (unsigned long) node->ats);
      node->ats->dot_create (node->ats, f);
      break;

    case TS_STRUCT_UNION:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sus);
      fprintf (f, "\t%lu [label=\"struct-or-union specifier\"]\n",
               (unsigned long) node->sus);
      node->sus->dot_create (node->sus, f);
      break;

    case TS_ENUM:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->es);
      fprintf (f, "\t%lu [label=\"enum specifier\"]\n",
               (unsigned long) node->es);
      node->es->dot_create (node->es, f);
      break;

    case TS_TYPEDEF:
      do_term (node, f, node->typedef_name, 0);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct type_specifier *node, FILE * f, const char *token,
         int n_token)
{
  assert (node != NULL);
  assert (f != NULL);
  assert (token != NULL);
  assert (n_token >= 0);

  fprintf (f, "\t%lu -> %lu%d;\n", (unsigned long) node,
           (unsigned long) node, n_token);
  fprintf (f, "\t%lu%d [label=\"%s\",shape=box,fontname=Courier]\n",
           (unsigned long) node, n_token, token);
}
