#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "direct_declarator.h"
#include "declarator.h"
#include "type_qualifier_list.h"
#include "assignment_expression.h"
#include "parameter_type_list.h"
#include "identifier_list.h"
#include "declaration.h"
#include "init_declarator.h"
#include "init_declarator_list.h"
#include "declaration_specifiers.h"
#include "storage_class_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static int do_child_1 (struct direct_declarator *node, FILE * f);
static void do_child_2 (struct direct_declarator *node, FILE * f);
static int do_child_3 (struct direct_declarator *node, FILE * f);
static int do_child_4 (struct direct_declarator *node, FILE * f);
static int do_child_5 (struct direct_declarator *node, FILE * f);
static void do_child_6 (struct direct_declarator *node, FILE * f);
static void do_term (struct direct_declarator *node, FILE * f,
                     const char *token, int n_token);
/* NOTE start of experimental code */
static int local_sem_analysis (void *Node);
/* NOTE end of experimental code */

struct direct_declarator *
direct_declarator_1 (const char *str)
{
  assert (str != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 1;
  buff->id = strdup (str);

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 2;
  buff->declr = ptr;
  buff->declr->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->declr->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_3 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 3;
  buff->ddeclr = ptr;
  buff->ddeclr->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_4 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 4;
  buff->ddeclr = ptr;
  buff->ddeclr->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_5 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 5;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->ddeclr->parent_kind = buff->tql->parent_kind =
    buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_6 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 6;
  buff->ddeclr = ptr1;
  buff->ass = ptr2;
  buff->ddeclr->parent_kind = buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_7 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 7;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ddeclr->parent_kind = buff->tql->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_8 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 8;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->ddeclr->parent_kind = buff->tql->parent_kind =
    buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_9 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 9;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ass = ptr3;
  buff->ddeclr->parent_kind = buff->tql->parent_kind =
    buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_10 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 10;
  buff->ddeclr = ptr1;
  buff->tql = ptr2;
  buff->ddeclr->parent_kind = buff->tql->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->tql->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_11 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 11;
  buff->ddeclr = ptr1;
  buff->ass = ptr2;
  buff->ddeclr->parent_kind = buff->ass->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->ass->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_12 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 12;
  buff->ddeclr = ptr1;
  buff->ptl = ptr2;
  buff->ddeclr->parent_kind = buff->ptl->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->ptl->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_13 (void *ptr)
{
  assert (ptr != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 13;
  buff->ddeclr = ptr;
  buff->ddeclr->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct direct_declarator *
direct_declarator_14 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct direct_declarator *buff =
    calloc (1, sizeof (struct direct_declarator));
  assert (buff != NULL);
  buff->kind = NODE_DIRECT_DECLARATOR;
  buff->n_prod = 14;
  buff->ddeclr = ptr1;
  buff->il = ptr2;
  buff->ddeclr->parent_kind = buff->il->parent_kind = NODE_DIRECT_DECLARATOR;
  buff->ddeclr->parent = buff->il->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct direct_declarator *node = Node;
  assert (node->kind == NODE_DIRECT_DECLARATOR);
  FILE *f = F;

  if (do_child_1 (node, f) == 1)
    return;
  do_child_2 (node, f);
  if (do_child_3 (node, f) == 1)
    return;
  if (do_child_4 (node, f) == 1)
    return;
  if (do_child_5 (node, f) == 1)
    return;
  do_child_6 (node, f);
}

static int
do_child_1 (struct direct_declarator *node, FILE * f)
{
  assert (node != NULL);
  assert (node->kind == NODE_DIRECT_DECLARATOR);
  assert (f != NULL);

  if (node->n_prod == 1)
    {
      do_term (node, f, node->id, 0);
      /* and we're done */
      return 1;
    }
  else if (node->n_prod == 2)
    do_term (node, f, "(", 0);
  else if (node->n_prod > 2 && node->n_prod <= 14)
    {
      assert (node->ddeclr != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ddeclr);
      fprintf (f, "\t%lu [label=\"direct declarator\"]\n",
               (unsigned long) node->ddeclr);
      node->ddeclr->dot_create (node->ddeclr, f);
    }
  else
    {                           /* BUG! */
    }

  return 0;
}

static void
do_child_2 (struct direct_declarator *node, FILE * f)
{
  assert (node != NULL);
  assert (node->kind == NODE_DIRECT_DECLARATOR);
  assert (f != NULL);

  if (node->n_prod == 2)
    {
      assert (node->declr != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->declr);
      fprintf (f, "\t%lu [label=\"declarator\"]\n",
               (unsigned long) node->declr);
      node->declr->dot_create (node->declr, f);
    }
  else if (node->n_prod > 2 && node->n_prod <= 11)
    do_term (node, f, "[", 1);
  else if (node->n_prod > 11 && node->n_prod <= 14)
    do_term (node, f, "(", 1);
  else
    {                           /* BUG! */
    }
}

static int
do_child_3 (struct direct_declarator *node, FILE * f)
{
  assert (node != NULL);
  assert (node->kind == NODE_DIRECT_DECLARATOR);
  assert (f != NULL);

  switch (node->n_prod)
    {
    case 2:
    case 13:
      do_term (node, f, ")", 2);
      /* and we're done */
      return 1;

    case 3:
      do_term (node, f, "]", 2);
      /* and we're done */
      return 1;

    case 4:
      do_term (node, f, "*", 2);
      break;

    case 5:
    case 6:
      do_term (node, f, "static", 2);
      break;

    case 7:
    case 8:
    case 9:
    case 10:
      assert (node->tql != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->tql);
      fprintf (f, "\t%lu [label=\"type qualifier list\"]\n",
               (unsigned long) node->tql);
      node->tql->dot_create (node->tql, f);
      break;

    case 11:
      assert (node->ass != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ass);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) node->ass);
      node->ass->dot_create (node->ass, f);
      break;

    case 12:
      assert (node->ptl != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ptl);
      fprintf (f, "\t%lu [label=\"parameter type list\"]\n",
               (unsigned long) node->ptl);
      node->ptl->dot_create (node->ptl, f);
      break;

    case 14:
      assert (node->il != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->il);
      fprintf (f, "\t%lu [label=\"identifier list\"]\n",
               (unsigned long) node->il);
      node->il->dot_create (node->il, f);
      break;

    default:;                  /* BUG! */
    }

  return 0;
}

static int
do_child_4 (struct direct_declarator *node, FILE * f)
{
  assert (node != NULL);
  assert (node->kind == NODE_DIRECT_DECLARATOR);
  assert (f != NULL);

  switch (node->n_prod)
    {
    case 4:
    case 10:
    case 11:
      do_term (node, f, "]", 3);
      /* and we're done */
      return 1;

    case 5:
      assert (node->tql != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->tql);
      fprintf (f, "\t%lu [label=\"type qualifier list\"]\n",
               (unsigned long) node->tql);
      node->tql->dot_create (node->tql, f);
      break;

    case 6:
    case 9:
      assert (node->ass != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ass);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) node->ass);
      node->ass->dot_create (node->ass, f);
      break;

    case 7:
      do_term (node, f, "*", 3);
      break;

    case 8:
      do_term (node, f, "static", 3);
      break;

    case 12:
    case 14:
      do_term (node, f, ")", 3);
      /* and we're done */
      return 1;

    default:;                  /* BUG! */
    }

  return 0;
}

static int
do_child_5 (struct direct_declarator *node, FILE * f)
{
  assert (node != NULL);
  assert (node->kind == NODE_DIRECT_DECLARATOR);
  assert (f != NULL);

  switch (node->n_prod)
    {
    case 5:
    case 8:
      assert (node->ass != NULL);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ass);
      fprintf (f, "\t%lu [label=\"assignment expression\"]\n",
               (unsigned long) node->ass);
      node->ass->dot_create (node->ass, f);
      break;

    case 6:
    case 7:
    case 9:
      do_term (node, f, "]", 4);
      /* and we're done */
      return 1;

    default:;                  /* BUG! */
    }

  return 0;
}

static void
do_child_6 (struct direct_declarator *node, FILE * f)
{
  assert (node != NULL);
  assert (node->kind == NODE_DIRECT_DECLARATOR);
  assert (f != NULL);

  if (node->n_prod == 5 || node->n_prod == 8)
    do_term (node, f, "]", 5);
  else
    {                           /* BUG! */
    }
}

static void
do_term (struct direct_declarator *node, FILE * f, const char *token,
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

/* NOTE start of experimental code */
static int
local_sem_analysis (void *Node)
{
  assert (Node != NULL);
  struct direct_declarator *node = Node;
  assert (node->kind == NODE_DIRECT_DECLARATOR);

  switch (node->n_prod)
    {
    case 1:                    /* identifier */
      /*
       * The declarator does not add
       * a type of its own, so we'll
       * rely on the declaration
       * specifiers.
       */
      node->type.type_kind = TYPE_UNKNOWN;
      break;

    case 2:                    /* parenthesis */
      if (node->declr->sem_analysis (node->declr) < 0)
        return -1;
      node->type = node->declr->type;
      break;

    case 3:                    /* array of unknwon size */
      node->type.type_kind = TYPE_ARRAY;
      node->type.array_type.n_cells = 0;
      /* the type of the element is in another place */
      break;

    case 4:                    /* VLA */
    case 5:                    /* static tql number */
    case 6:                    /* static number */
    case 7:                    /* tql VLA */
    case 8:                    /* tql static number */
    case 9:                    /* tql number */
    case 10:                   /* tql, no number */
      break;

    case 11:                   /* number */
      node->type.type_kind = TYPE_ARRAY;
      /* FIXME */ node->type.array_type.n_cells = 0;
      /* the type of the element is in another place */
      break;

    case 12:                   /* () parameter type list */
    case 13:                   /* function, empty */
    case 14:                   /* () identifier list */
      break;
    }

  return 0;
}

/* NOTE end of experimental code */
