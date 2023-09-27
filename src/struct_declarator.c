#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct_declarator.h"
#include "declarator.h"
#include "constant_expression.h"
#include "struct_declarator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct struct_declarator *node, FILE * f,
                     const char *token, int n_token);

struct struct_declarator *
struct_declarator_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declarator *buff =
    calloc (1, sizeof (struct struct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATOR;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_STRUCT_DECLARATOR;
  buff->expr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct struct_declarator *
struct_declarator_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declarator *buff =
    calloc (1, sizeof (struct struct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATOR;
  buff->dclr = ptr1;
  buff->expr = ptr2;
  buff->dclr->parent_kind = buff->expr->parent_kind = NODE_STRUCT_DECLARATOR;
  buff->dclr->parent = buff->expr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct struct_declarator *
struct_declarator_3 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declarator *buff =
    calloc (1, sizeof (struct struct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATOR;
  buff->dclr = ptr;
  buff->dclr->parent_kind = NODE_STRUCT_DECLARATOR;
  buff->dclr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct struct_declarator *node = Node;
  assert (node->kind == NODE_STRUCT_DECLARATOR);
  FILE *f = F;

  if (node->dclr != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->dclr);
      fprintf (f, "\t%lu [label=\"declarator\"]\n",
               (unsigned long) node->dclr);
      node->dclr->dot_create (node->dclr, f);
    }
  if (node->expr != NULL)
    {
      do_term (node, f, ":", 0);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->expr);
      fprintf (f, "\t%lu [label=\"constant expression\"]\n",
               (unsigned long) node->expr);
      node->expr->dot_create (node->expr, f);
    }
}

static void
do_term (struct struct_declarator *node, FILE * f, const char *token,
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
