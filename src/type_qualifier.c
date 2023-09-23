#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "type_qualifier.h"
#include "declaration_specifiers.h"
#include "specifier_qualifier_list.h"
#include "type_qualifier_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);

struct type_qualifier *
type_qualifier_1 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_CONST;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_qualifier *
type_qualifier_2 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_RESTRICT;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_qualifier *
type_qualifier_3 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_VOLATILE;

  buff->dot_create = local_dot_create;

  return buff;
}

struct type_qualifier *
type_qualifier_4 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_ATOMIC;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct type_qualifier *node = Node;
  assert (node->kind == NODE_TYPE_QUALIFIER);
  FILE *f = F;

  switch (node->tq_kind)
    {
    case TQ_CONST:
      fprintf (f, "\t%lu [label=\"const\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TQ_RESTRICT:
      fprintf (f, "\t%lu [label=\"restrict\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TQ_VOLATILE:
      fprintf (f, "\t%lu [label=\"volatile\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    case TQ_ATOMIC:
      fprintf (f, "\t%lu [label=\"_Atomic\",fontname=Courier,shape=box]\n",
               (unsigned long) node);
      break;

    default:;                  /* BUG! */
    }
}
