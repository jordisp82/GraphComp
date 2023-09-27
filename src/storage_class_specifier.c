#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "storage_class_specifier.h"
#include "declaration_specifiers.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct storage_class_specifier *node, FILE * f,
                     const char *token, int n_token);

struct storage_class_specifier *
storage_class_specifier_1 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_TYPEDEF;

  buff->dot_create = local_dot_create;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_2 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_EXTERN;

  buff->dot_create = local_dot_create;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_3 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_STATIC;

  buff->dot_create = local_dot_create;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_4 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_THREAD_LOCAL;

  buff->dot_create = local_dot_create;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_5 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_AUTO;

  buff->dot_create = local_dot_create;

  return buff;
}

struct storage_class_specifier *
storage_class_specifier_6 (void)
{
  struct storage_class_specifier *buff =
    calloc (1, sizeof (struct storage_class_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->value = STG_REGISTER;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct storage_class_specifier *node = Node;
  assert (node->kind == NODE_STORAGE_CLASS_SPECIFIER);
  FILE *f = F;

  switch (node->value)
    {
    case STG_TYPEDEF:
      do_term (node, f, "typedef", 0);
      break;

    case STG_EXTERN:
      do_term (node, f, "extern", 0);
      break;

    case STG_STATIC:
      do_term (node, f, "static", 0);
      break;

    case STG_THREAD_LOCAL:
      do_term (node, f, "_Thread_local", 0);
      break;

    case STG_AUTO:
      do_term (node, f, "auto", 0);
      break;

    case STG_REGISTER:
      do_term (node, f, "register", 0);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct storage_class_specifier *node, FILE * f, const char *token,
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
