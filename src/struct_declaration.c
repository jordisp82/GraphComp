#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct_declaration.h"
#include "specifier_qualifier_list.h"
#include "struct_declarator_list.h"
#include "static_assert_declaration.h"
#include "struct_declaration_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct struct_declaration *node, FILE * f,
                     const char *token, int n_token);

struct struct_declaration *
struct_declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declaration *buff =
    calloc (1, sizeof (struct struct_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION;
  buff->sql = ptr;
  buff->sql->parent_kind = NODE_STRUCT_DECLARATION;
  buff->sql->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct struct_declaration *
struct_declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declaration *buff =
    calloc (1, sizeof (struct struct_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION;
  buff->sql = ptr1;
  buff->sdl = ptr2;
  buff->sql->parent_kind = buff->sdl->parent_kind = NODE_STRUCT_DECLARATION;
  buff->sql->parent = buff->sdl->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

struct struct_declaration *
struct_declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declaration *buff =
    calloc (1, sizeof (struct struct_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION;
  buff->sad = ptr;
  buff->sad->parent_kind = NODE_STRUCT_DECLARATION;
  buff->sad->parent = buff;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct struct_declaration *node = Node;
  assert (node->kind == NODE_STRUCT_DECLARATION);
  FILE *f = F;

  if (node->sql != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sql);
      fprintf (f, "\t%lu [label=\"specifier qualifier list\"]\n",
               (unsigned long) node->sql);
      if (node->sdl != NULL)
        {
          fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                   (unsigned long) node->sdl);
          fprintf (f, "\t%lu [label=\"struct declarator list\"]\n",
                   (unsigned long) node->sdl);
          node->sdl->dot_create (node->sdl, f);
        }
      do_term (node, f, ",", 0);
    }
  else if (node->sad != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sad);
      fprintf (f, "\t%lu [label=\"static assert declaration\"]\n",
               (unsigned long) node->sad);
      node->sad->dot_create (node->sad, f);
    }
}

static void
do_term (struct struct_declaration *node, FILE * f, const char *token,
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
