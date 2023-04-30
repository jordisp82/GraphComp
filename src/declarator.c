#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "declarator.h"
#include "ast.h"
#include "nonterms.h"
#include "dir_declr.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_pointers (declarator_t * dr, ast_node_t * ast);
static ast_node_t *find_pointer_child (ast_node_t * ast);
static type_qual_t find_type_qual_in_pointer (ast_node_t * ast);
static type_qual_t type_quals_in_pointer (ast_node_t * ast);

declarator_t *
sem_declarator (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (ast->children != NULL);
  assert (IS_DECLARATOR (ast->func_ptr));

  declarator_t *dr = calloc (1, sizeof (declarator_t));
  assert (dr != NULL);

  dr->n_pointers = 0;
  dr->pointers = NULL;

  if (ast->func_ptr == declarator_1)
    {
      sem_pointers (dr, ast);
      dr->dir_declr = sem_direct_declarator (ast->children[1]);
    }
  else if (ast->func_ptr == declarator_2)
    dr->dir_declr = sem_direct_declarator (ast->children[0]);

  return dr;
}

static void
sem_pointers (declarator_t * dr, ast_node_t * ast)
{
  assert (dr != NULL);
  assert (ast != NULL);

  dr->n_pointers = 1;
  ast_node_t *ptr;
  ast_node_t *child;

  for (ptr = ast->children[0]; (child = find_pointer_child (ptr)) != NULL;
       ptr = child)
    dr->n_pointers++;

  dr->pointers = calloc (dr->n_pointers, sizeof (pointer_t *));
  assert (dr->pointers != NULL);

  int i = 0;
  for (ptr = ast->children[0]; (child = find_pointer_child (ptr)) != NULL;
       ptr = child)
    {
      dr->pointers[i] = calloc (1, sizeof (pointer_t));
      assert (dr->pointers[i] != NULL);
      dr->pointers[i]->type_qual = find_type_qual_in_pointer (ptr);
    }
}

static ast_node_t *
find_pointer_child (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_POINTER (ast->func_ptr));

  for (int i = 0; i < ast->n_children; i++)
    if (IS_POINTER (ast->children[i]->func_ptr))
      return ast->children[i];

  return NULL;
}

static type_qual_t
find_type_qual_in_pointer (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_POINTER (ast->func_ptr));
  assert (ast->children != NULL);

  type_qual_t empty = { 0 };

  if (ast->func_ptr == pointer_1 || ast->func_ptr == pointer_2)
    return type_quals_in_pointer (ast->children[1]);
  else
    return empty;
}

static type_qual_t
type_quals_in_pointer (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_TYPE_QUALIFIER_LIST (ast->func_ptr));

  type_qual_t ret = { 0 };

  ast_node_t *ptr = ast->children[0];
  while (1)
    {
      if (IS_TYPE_QUAL (ptr->func_ptr))
        {
          switch (ptr->token)
            {
            case CONST:
              ret.n_const++;
              break;

            case RESTRICT:
              ret.n_restrict++;
              break;

            case VOLATILE:
              ret.n_volatile++;
              break;

            case ATOMIC:
              ret.n_atomic++;
              break;
            }
          break;
        }
      else
        ptr = ptr->children[1]->children[0];
    }

  return ret;
}
