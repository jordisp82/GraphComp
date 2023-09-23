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
      fprintf (f, "\t%lu [label=\"typedef\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case STG_EXTERN:
      fprintf (f, "\t%lu [label=\"extern\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case STG_STATIC:
      fprintf (f, "\t%lu [label=\"static\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case STG_THREAD_LOCAL:
      fprintf (f,
               "\t%lu [label=\"_Thread_local\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case STG_AUTO:
      fprintf (f, "\t%lu [label=\"auto\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case STG_REGISTER:
      fprintf (f, "\t%lu [label=\"register\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    default:;                  /* BUG! */
    }
}
