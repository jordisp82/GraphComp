#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_or_union_specifier.h"
#include "struct_or_union.h"
#include "struct_declaration_list.h"
#include "type_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct struct_or_union_specifier *node, FILE * f,
                     const char *token, int n_token);

struct struct_or_union_specifier *
struct_or_union_specifier_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_or_union_specifier *buff =
    calloc (1, sizeof (struct struct_or_union_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su = ptr1;
  buff->sdl = ptr2;
  buff->su->parent_kind = buff->sdl->parent_kind =
    NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su->parent = buff->sdl->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct struct_or_union_specifier *
struct_or_union_specifier_2 (void *ptr1, const char *str, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (str != NULL);
  assert (ptr3 != NULL);

  struct struct_or_union_specifier *buff =
    calloc (1, sizeof (struct struct_or_union_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su = ptr1;
  buff->sdl = ptr3;
  buff->tag = strdup (str);
  assert (buff->tag != NULL);
  buff->su->parent_kind = buff->sdl->parent_kind =
    NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su->parent = buff->sdl->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct struct_or_union_specifier *
struct_or_union_specifier_3 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct struct_or_union_specifier *buff =
    calloc (1, sizeof (struct struct_or_union_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su = ptr1;
  buff->tag = strdup (str);
  assert (buff->tag != NULL);
  buff->su->parent_kind = NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct struct_or_union_specifier *node = Node;
  assert (node->kind == NODE_STRUCT_OR_UNION_SPECIFIER);
  FILE *f = F;

  assert (node->su != NULL);
  fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
           (unsigned long) node->su);
  fprintf (f, "\t%lu [label=\"struct-or-union\"]\n",
           (unsigned long) node->su);
  node->su->dot_create (node->su, f);

  if (node->tag != NULL)
    do_term (node, f, node->tag, 0);
  if (node->sdl != NULL)
    {
      do_term (node, f, "{", 1);
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sdl);
      fprintf (f, "\t%lu [label=\"struct declaration list\"]\n",
               (unsigned long) node->sdl);
      node->sdl->dot_create (node->sdl, f);
      do_term (node, f, "}", 2);
    }
}

static void
do_term (struct struct_or_union_specifier *node, FILE * f, const char *token,
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
