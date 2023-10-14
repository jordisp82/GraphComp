#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "declaration.h"
#include "declaration_specifiers.h"
#include "init_declarator_list.h"
#include "static_assert_declaration.h"
#include "external_declaration.h"
#include "block_item.h"
#include "block_item_list.h"
#include "declaration_list.h"
#include "function_definition.h"
#include "ast.h"
#include "iteration_statement.h"
#include "declaration_list.h"
/* NOTE start of experimental code */
#include "type_specifier.h"
#include "struct_or_union_specifier.h"
#include "enum_specifier.h"
#include "init_declarator.h"
#include "type_t.h"
/* NOTE end of experimental code */

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct declaration *node, FILE * f,
                     const char *token, int n_token);
/* NOTE start of experimental code */
static int sem_analysis_1 (void *Node);
static int sem_analysis_2 (void *Node);
static int sem_analysis_3 (void *Node);
#if 0
static void proc_init_declr (struct init_declarator *id,
                             struct declaration_specifiers *ds);
#endif
/* NOTE end of experimental code */

struct declaration *
declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr;
  buff->ds->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = sem_analysis_1;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration *
declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr1;
  buff->idl = ptr2;
  buff->ds->parent_kind = buff->idl->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff->idl->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = sem_analysis_2;
  /* NOTE end of experimental code */

  if (look_for_typedef (buff->ds) == 1)
    register_ids_as_typedef (buff->idl);

  return buff;
}

struct declaration *
declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->sad = ptr;
  buff->sad->parent_kind = NODE_DECLARATION;
  buff->sad->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = sem_analysis_3;
  /* NOTE end of experimental code */

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct declaration *node = Node;
  assert (node->kind == NODE_DECLARATION);
  FILE *f = F;

  if (node->ds != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->ds);
      fprintf (f, "\t%lu [label=\"declaration specifiers\"]\n",
               (unsigned long) node->ds);
      node->ds->dot_create (node->ds, f);
      do_term (node, f, ";", 0);
    }
  if (node->idl != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->idl);
      fprintf (f, "\t%lu [label=\"init declarator list\"]\n",
               (unsigned long) node->idl);
      node->idl->dot_create (node->idl, f);
      do_term (node, f, ";", 0);
    }
  if (node->sad != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->sad);
      fprintf (f, "\t%lu [label=\"static assert declaration\"]\n",
               (unsigned long) node->sad);
      node->sad->dot_create (node->sad, f);
    }
}

static void
do_term (struct declaration *node, FILE * f, const char *token, int n_token)
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

/*
 * In a declaration, we can:
 * (a) declare a new type (with a tag),
 * (b) declare a new type (with typedef),
 * (c) declare new things (objects or functions).
 * Case (a) can be done without declarators,
 * but cases (b) and (c) must use declarators.
 * When it comes to objects and functions,
 * their type is declared not in a single place,
 * but in part in the declaration specifiers and
 * in part in the declarators themselves.
 */


static int
sem_analysis_1 (void *Node)
{
  assert (Node != NULL);

  struct declaration *node = Node;
  assert (node->kind == NODE_DECLARATION);

  /*
   * 6.7, paragraph 2:
   * since we have no declarator, then we
   * must declare a tag or the members of
   * an enumeration.
   */

  if (node->ds->sem_analysis (node->ds) < 0)
    return -1;

  switch (node->ds->type.type_kind)
    {
    case TYPE_STRUCT:
      if (node->ds->type.struct_type.tag == NULL)
        printf ("[%s:%d]<%s> useless declaration found.\n", __FILE__,
                __LINE__, __func__);
      break;

    case TYPE_UNION:
      if (node->ds->type.union_type.tag == NULL)
        printf ("[%s:%d]<%s> useless declaration found.\n", __FILE__,
                __LINE__, __func__);
      break;

    case TYPE_ENUM:
      /* TODO */
      break;

    default:
      printf ("[%s:%d]<%s> useless declaration found.\n", __FILE__, __LINE__,
              __func__);
      break;
    }

  /* TODO add the new type to the symbol table */

  return 0;
}

static int
sem_analysis_2 (void *Node)
{
  assert (Node != NULL);

  struct declaration *node = Node;
  assert (node->kind == NODE_DECLARATION);

  if (node->ds->sem_analysis (node->ds) < 0)
    return -1;

  /*
   * The fact that there are declarators
   * does not prevent the declaration
   * from declaring new tags or enumeration
   * members --- and we may have typedefs.
   */

  if (node->idl->sem_analysis (node->idl) < 0)
    return -1;

  /*
   * TODO
   * For each init declarator, we need to get
   * the "part of the type" of the declarator
   * and then mix it with the part of the type
   * of the declaration specifiers, to get the
   * combined type.
   */

  return 0;
}

static int
sem_analysis_3 (void *Node)
{
  assert (Node != NULL);

  struct declaration *node = Node;
  assert (node->kind == NODE_DECLARATION);

  /* NOTE so far nothing to check on static assert declarations */

  return 0;
}

#if 0
static void
proc_init_declr (struct init_declarator *id,
                 struct declaration_specifiers *ds)
{
  assert (id != NULL);
  assert (ds != NULL);
  assert (id->kind == NODE_INIT_DECLARATOR);
  assert (ds->kind == NODE_DECLARATION_SPECIFIERS);


}

/* NOTE end of experimental code */
#endif
