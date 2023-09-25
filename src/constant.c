#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constant.h"
#include "primary_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct constant *node, FILE * f,
                     const char *token, int n_token);

struct constant *
constant_1 (int value)
{
  struct constant *buff = calloc (1, sizeof (struct constant));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT;
  buff->const_kind = CONST_INTEGER;
  buff->integer = value;

  buff->dot_create = local_dot_create;

  return buff;
}

struct constant *
constant_2 (double value)
{
  struct constant *buff = calloc (1, sizeof (struct constant));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT;
  buff->const_kind = CONST_FLOAT;
  buff->floating = value;

  buff->dot_create = local_dot_create;

  return buff;
}

struct constant *
constant_3 (const char *str)
{
  assert (str != NULL);

  struct constant *buff = calloc (1, sizeof (struct constant));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT;
  buff->const_kind = CONST_ENUM;
  buff->string = strdup (str);
  assert (buff->string != NULL);

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct constant *node = Node;
  assert (node->kind == NODE_CONSTANT);
  FILE *f = F;

  char *aux = NULL;

  switch (node->const_kind)
    {
    case CONST_INTEGER:
      asprintf (&aux, "%d", node->integer);     /* FIXME what if uint64? */
      do_term (node, f, aux, 0);
      free (aux);
      break;

    case CONST_FLOAT:
      asprintf (&aux, "%f", node->floating);    /* FIXME what if long double? */
      do_term (node, f, aux, 0);
      free (aux);
      break;

    case CONST_ENUM:
      do_term (node, f, node->string, 0);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct constant *node, FILE * f, const char *token, int n_token)
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
