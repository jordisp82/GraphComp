#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "declaration.h"
#include "ast.h"
#include "decl_specs.h"
#include "declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_init_declr_list (declaration_t * decl, ast_node_t * ast);
static init_declr_t *sem_init_declr (ast_node_t * ast);

declaration_t *
sem_declaration (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_DECLARATION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  if (ast->func_ptr == declaration_3)
    return NULL;                /* static assert declaration */

  declaration_t *decl = calloc (1, sizeof (declaration_t));
  assert (decl != NULL);

  decl->decl_specs = sem_decl_specs (ast->children[0]);
  if (ast->func_ptr == declaration_2)
    sem_init_declr_list (decl, ast);

  return decl;
}

static void
sem_init_declr_list (declaration_t * decl, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (decl != NULL);
  assert (IS_DECLARATION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  decl->n_ideclrs = 1;
  ast_node_t *ptr;

  for (ptr = ast->children[0]; ptr->n_children > 1; ptr = ptr->children[0])
    decl->n_ideclrs++;

  decl->ideclrs = calloc (decl->n_ideclrs, sizeof (init_declr_t *));
  assert (decl->ideclrs != NULL);

  for (ptr = ast; IS_INIT_DECLARATOR_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  decl->ideclrs[0] = sem_init_declr (ptr->children[0]);
  ptr = ptr->parent;
  for (int i = 1; IS_INIT_DECLARATOR (ptr->func_ptr); ptr = ptr->parent, i++)
    decl->ideclrs[i] = sem_init_declr (ptr->children[1]);
}


static init_declr_t *
sem_init_declr (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_INIT_DECLARATOR (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  init_declr_t *idr = calloc (1, sizeof (init_declr_t));
  assert (idr != NULL);

  idr->declr = sem_declarator (ast->children[0]);
  /* TODO initializer, if it exists */

  return idr;
}
