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
static int type_spec_alone (struct declaration *node,
                            struct type_specifier *ts);
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

  /*
   * 6.7, paragraphs 3 and 4 are outside
   * the scope of the semantic analysis
   * in this AST node.
   */

  if (node->ds->sem_analysis < 0)
    return -1;

  int v = 0;

  for (struct ds_node * ptr = node->ds->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_STORAGE_CLASS_SPECIFIER:
      case NODE_TYPE_QUALIFIER:
      case NODE_FUNCTION_SPECIFIER:
        /* they are relevant for objects or functions, not for types */
        break;

      case NODE_TYPE_SPECIFIER:
        if (type_spec_alone (node, ptr->ts) == 1)
          v = 1;
        break;

      default:;                /* BUG! */
      }

  if (v == 0)
    printf ("[%s:%d]<%s> useless declaration found.\n", __FILE__, __LINE__,
            __func__);
  else
    {
      type_t type = node->ds->create_type (node->ds);
      /* TODO */
      if (type.type_kind == TYPE_UNKNOWN)
        return -1;
    }

  return 0;
}

static int
sem_analysis_2 (void *Node)
{
  assert (Node != NULL);

  struct declaration *node = Node;
  assert (node->kind == NODE_DECLARATION);

  if (node->ds->sem_analysis < 0)
    return -1;

  /*
   * 6.7.1 paragraph 4:
   * "_Thread_local shall not appear in the
   * declaration specifiers of a function
   * declaration".
   */

  /*
   * 6.7.1 paragraph 7:
   * "The declaration of an identifier for a
   * function that has block scope shall have
   * no explicit storage-class specifier
   * other than extern.
   */

  /* TODO */

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

static int
type_spec_alone (struct declaration *node, struct type_specifier *ts)
{
  assert (node != NULL);
  assert (ts != NULL);
  assert (ts->kind == NODE_TYPE_SPECIFIER);

  /*
   * A type specifier alone in a declaration
   * makes sense when it declares a new
   * struct, union or enum tag.
   * NOTE fuck atomic type specifiers for now.
   */

  switch (ts->ts_kind)
    {
    case TS_STRUCT_UNION:
      if (ts->sus->tag != NULL)
        return 1;
      else
        return 0;

    case TS_ENUM:
      if (ts->es->tag != NULL)
        return 1;
      else
        return 0;
      break;

    case TS_VOID:
    case TS_CHAR:
    case TS_SHORT:
    case TS_INT:
    case TS_LONG:
    case TS_FLOAT:
    case TS_DOUBLE:
    case TS_SIGNED:
    case TS_UNSIGNED:
    case TS_BOOL:
    case TS_COMPLEX:
    case TS_IMAGINARY:
    case TS_ATOMIC:
    case TS_TYPEDEF:
      return 0;

    default:;                  /* BUG! */
    }

  return 0;
}

/* NOTE end of experimental code */
