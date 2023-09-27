#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "direct_abstract_declarator.h"
#include "abstract_declarator.h"
#include "type_qualifier_list.h"
#include "assignment_expression.h"
#include "parameter_type_list.h"
#include "abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_child_1 (struct direct_abstract_declarator *node, FILE * f);
static void do_child_2 (struct direct_abstract_declarator *node, FILE * f);
static void do_child_3 (struct direct_abstract_declarator *node, FILE * f);
static void do_term (struct direct_abstract_declarator *node, FILE * f,
                     const char *token, int n_token);

struct direct_abstract_declarator *
direct_abstract_declarator_1 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 1;
  buff->adclr = ptr;
  buff->adclr->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->adclr->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_2 (void)
{
  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 2;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_3 (void)
{
  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 3;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_4 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 4;
  buff->tql = ptr1;
  buff->ass = ptr2;
  buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->tql->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_5 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 5;
  buff->ass = ptr;
  buff->ass->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_6 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 6;
  buff->tql = ptr1;
  buff->ass = ptr2;
  buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->tql->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_7 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 7;
  buff->tql = ptr1;
  buff->ass = ptr2;
  buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->tql->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_8 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 8;
  buff->tql = ptr;
  buff->tql->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->tql->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_9 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 9;
  buff->ass = ptr;
  buff->ass->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_10 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 10;
  buff->dad = ptr;
  buff->dad->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_11 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 11;
  buff->dad = ptr;
  buff->dad->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_12 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 12;
  buff->dad = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->dad->parent_kind = buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->tql->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_13 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 13;
  buff->dad = ptr1;
  buff->ass = ptr2;
  buff->dad->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_14 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 14;
  buff->dad = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->dad->parent_kind = buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->tql->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_15 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 15;
  buff->dad = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->dad->parent_kind = buff->tql->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->tql->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_16 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 16;
  buff->dad = ptr1;
  buff->tql = ptr2;
  buff->dad->parent_kind = buff->tql->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->tql->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_17 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 17;
  buff->dad = ptr1;
  buff->ass = ptr2;
  buff->dad->parent_kind = buff->ass->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_18 (void)
{
  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 18;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_19 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 19;
  buff->ptl = ptr;
  buff->ptl->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->ptl->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_20 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 20;
  buff->dad = ptr;
  buff->dad->parent_kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct direct_abstract_declarator *
direct_abstract_declarator_21 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_abstract_declarator *buff =
    calloc (1, sizeof (struct direct_abstract_declarator));
  assert (buff);
  buff->kind = NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->n_prod = 21;
  buff->dad = ptr1;
  buff->ptl = ptr2;
  buff->dad->parent_kind = buff->ptl->parent_kind =
    NODE_DIRECT_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff->ptl->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct direct_abstract_declarator *node = Node;
  assert (node->kind == NODE_DIRECT_ABSTRACT_DECLARATOR);
  FILE *f = F;

  do_child_1 (node, f);
  do_child_2 (node, f);
  do_child_3 (node, f);
}

static void
do_child_1 (struct direct_abstract_declarator *node, FILE * f)
{
  assert (node != NULL);
  assert (f != NULL);

  switch (node->n_prod)
    {
    case 1:
    case 18:
    case 19:
      do_term (node, f, "(", 0);
      break;

    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      do_term (node, f, "[", 0);
      break;

    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 20:
    case 21:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->dad);
      fprintf (f, "\t%lu [label=\"direct abstract declarator\"]\n",
               (unsigned long) node->dad);
      node->dad->dot_create (node->dad, f);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_child_2 (struct direct_abstract_declarator *node, FILE * f)
{
  assert (node != NULL);
  assert (f != NULL);

  switch (node->n_prod)
    {
    case 1:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->adclr);
      fprintf (f, "\t%lu [label=\"abstract declarator\"]\n",
               (unsigned long) node->adclr);
      node->adclr->dot_create (node->adclr, f);
      break;

    case 2:
      do_term (node, f, "]", 1);
      break;

    case 3:
      do_term (node, f, "*", 1);
      break;

    case 4:
    case 5:
      do_term (node, f, "static", 1);
      break;

    case 6:
    case 7:
    case 8:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->tql);
      fprintf (f, "\t%lu [label=\"type qualifier list\"]\n",
               (unsigned long) node->tql);
      node->tql->dot_create (node->tql, f);
      break;

    case 9:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ass);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) node->ass);
      node->ass->dot_create (node->ass, f);
      break;

    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
      do_term (node, f, "[", 1);
      break;

    case 18:
      do_term (node, f, ")", 1);
      break;

    case 19:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ptl);
      fprintf (f, "\t%lu [label=\"parameter type list\"]\n",
               (unsigned long) node->ptl);
      node->ptl->dot_create (node->ptl, f);
      break;

    case 20:
    case 21:
      do_term (node, f, "(", 1);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_child_3 (struct direct_abstract_declarator *node, FILE * f)
{
  assert (node != NULL);
  assert (f != NULL);

  switch (node->n_prod)
    {
    case 1:
    case 19:
    case 20:
      do_term (node, f, ")", 2);
      break;

    case 2:
    case 18:
      return;

    case 3:
    case 8:
    case 9:
    case 10:
      do_term (node, f, "]", 2);
      break;

    case 4:
    case 14:
    case 15:
    case 16:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->tql);
      fprintf (f, "\t%lu [label=\"type qualifier list\"]\n",
               (unsigned long) node->tql);
      node->tql->dot_create (node->tql, f);
      break;

    case 5:
    case 7:
    case 17:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ass);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) node->ass);
      node->ass->dot_create (node->ass, f);
      break;

    case 6:
    case 12:
    case 13:
      do_term (node, f, "static", 2);
      break;

    case 11:
      do_term (node, f, "*", 2);
      break;

    case 21:
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ptl);
      fprintf (f, "\t%lu [label=\"parameter type list\"]\n",
               (unsigned long) node->ptl);
      node->ptl->dot_create (node->ptl, f);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct direct_abstract_declarator *node, FILE * f, const char *token,
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
