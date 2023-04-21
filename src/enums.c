#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "enums.h"
#include "ast.h"
#include "declaration_t.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_enum1 (ast_node_t * ast);
static void sem_enum2 (ast_node_t * ast);
static void sem_enum3 (ast_node_t * ast);
static void sem_enum_list (ast_node_t * ast);
static void sem_enumerator (ast_node_t * ast);

void
sem_enum (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUM_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  enum_t *ptr = calloc (1, sizeof (enum_t));
  assert (ptr != NULL);
  if (ast->data != NULL)
    ptr->tag = ast->data;
  ast->data = ptr;
  ptr->enum_consts = calloc (1, sizeof (enum_const_t));
  assert (ptr->enum_consts != NULL);

  /*
   * (a) and (b): enum without tag with constants
   * (c) and (d): enum with tag and constants
   * (e): enum with tag without constants
   */

  if (ast->func_ptr == enum_spec_1 || ast->func_ptr == enum_spec_2)
    sem_enum1 (ast);
  else if (ast->func_ptr == enum_spec_3 || ast->func_ptr == enum_spec_4)
    sem_enum2 (ast);
  else if (ast->func_ptr == enum_spec_5)
    sem_enum3 (ast);

  assert (ast->data != NULL);   /* FIXME only for debugging purposes */
}

static void
sem_enum1 (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUM_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);
  assert (IS_ENUMERATOR_LIST (ast->children[0]->func_ptr));

  sem_enum_list (ast->children[0]);
}

static void
sem_enum2 (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUM_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);
  assert (IS_ENUMERATOR_LIST (ast->children[0]->func_ptr));

  sem_enum_list (ast->children[0]);
}

static void
sem_enum3 (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUM_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /* NOTE do nothing? */
}

static void
sem_enum_list (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUMERATOR_LIST (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);

  ast->data = ast->parent->data;

  for (int i = 0; i < ast->n_children; i++)
    if (IS_ENUMERATOR (ast->children[i]->func_ptr))
      sem_enumerator (ast->children[i]);
    else if (IS_ENUMERATOR_LIST (ast->children[i]->func_ptr))
      sem_enum_list (ast->children[i]);
}

static void
sem_enumerator (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUMERATOR (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);

  enum_const_t *ptr1 = calloc (1, sizeof (enum_const_t));
  assert (ptr1 != NULL);
  ast->data = ptr1;
  ptr1->name = strdup (ast->children[0]->data);
  assert (ptr1->name != NULL);
  if (ast->n_children > 1)
    ptr1->value = ast->children[1];
  enum_t *ptr2 = ast->parent->data;
  assert (ptr2 != NULL);
  ptr1->next = ptr2->enum_consts->next;
  ptr2->enum_consts->next = ptr1;
}
