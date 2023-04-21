#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
//#include <string.h>

#include "struct_union.h"
#include "ast.h"
#include "declaration_t.h"
#include "decl_specs.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_struct_decl_list (ast_node_t * ast);
static void sem_struct_decl (ast_node_t * ast);
static void sem_spec_qual_list (ast_node_t * ast);
static void sem_struct_declr_list (ast_node_t * ast);

void
sem_struct_union_spec (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_STRUCT_UNION_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  type_spec_t *ptr1 = ast->parent->data;
  if (ast->children[0]->token == STRUCT)
    ptr1->n_struct++;
  else if (ast->children[0]->token == UNION)
    ptr1->n_union++;

  struct_union_t *ptr2 = calloc (1, sizeof (struct_union_t));
  assert (ptr2 != NULL);
  if (ast->data != NULL)
    ptr2->tag = ast->data;
  ast->data = ptr2;
  ptr2->token = ast->children[0]->token;

  if (ast->func_ptr == struct_union_spec_3)
    return;                     /* nothing else to do */
}

static void
sem_struct_decl_list (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_STRUCT_DECLARATION_LIST (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);

  for (int i = 0; i < ast->n_children; i++)
    if (IS_STRUCT_DECLARATION (ast->children[i]->func_ptr))
      sem_struct_decl (ast->children[i]);
    else if (IS_STRUCT_DECLARATION_LIST (ast->children[i]->func_ptr))
      sem_struct_decl_list (ast->children[i]);
}

static void
sem_struct_decl (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_STRUCT_DECLARATION (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  if (ast->func_ptr == struct_declaration_3)
    return;

  sem_spec_qual_list (ast->children[0]);
  if (ast->func_ptr == struct_declaration_2)
    sem_struct_declr_list (ast->children[1]);
}

static void
sem_spec_qual_list (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_SPEC_QUAL_LIST (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);

  if (IS_TYPE_SPEC (ast->children[0]->func_ptr))
    sem_type_spec (ast->children[0]);
  else if (IS_TYPE_QUAL (ast->children[0]->func_ptr))
    sem_type_qual (ast->children[0]);

  if (ast->n_children > 1)
    sem_spec_qual_list (ast->children[1]);
}

static void
sem_struct_declr_list (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_STRUCT_DECLARATOR_LIST (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /* TODO quan hagi fet els declaradors */
}
