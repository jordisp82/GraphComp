#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "func_def.h"
#include "ast.h"
#include "nonterms.h"
#include "decl_specs.h"
#include "declarator.h"
#include "compound_stmt.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static func_def_t *sem_func_def_kr (ast_node_t * ast);
static func_def_t *sem_func_def_iso (ast_node_t * ast);
static decl_list_t *sem_decl_list (ast_node_t * ast);

func_def_t *
sem_func_def (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_FUNCTION_DEFINITION (ast->func_ptr));
  assert (ast->children != NULL && ast->n_children > 2);

  assert (IS_DECLARATION_SPECS (ast->children[0]->func_ptr));
  assert (IS_DECLARATOR (ast->children[1]->func_ptr));

  if (ast->func_ptr == function_definition_1)
    return sem_func_def_kr (ast);
  else if (ast->func_ptr == function_definition_2)
    return sem_func_def_iso (ast);

  return NULL;                  /* unreachable, in theory */
}

static func_def_t *
sem_func_def_kr (ast_node_t * ast)
{
  assert (ast->n_children == 4);
  assert (IS_DECLARATION_LIST (ast->children[2]->func_ptr));
  assert (IS_COMPOUND_STATEMENT (ast->children[3]->func_ptr));

  func_def_t *fd = calloc (1, sizeof (func_def_t));
  assert (fd != NULL);

  fd->decl_specs = sem_decl_specs (ast->children[0]);
  fd->declarator = sem_declarator (ast->children[1]);
  fd->decl_list = sem_decl_list (ast->children[2]);
  fd->compound_stmt = sem_compound_stmt (ast->children[3]);

  return fd;
}

static func_def_t *
sem_func_def_iso (ast_node_t * ast)
{
  assert (ast->n_children == 3);
  assert (IS_COMPOUND_STATEMENT (ast->children[2]->func_ptr));

  func_def_t *fd = calloc (1, sizeof (func_def_t));
  assert (fd != NULL);

  fd->decl_specs = sem_decl_specs (ast->children[0]);
  fd->declarator = sem_declarator (ast->children[1]);
  fd->compound_stmt = sem_compound_stmt (ast->children[2]);

  return fd;
}

static decl_list_t *
sem_decl_list (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_DECLARATION_LIST (ast->func_ptr));
  assert (ast->children != NULL && ast->n_children > 0);

  decl_list_t *dl = calloc (1, sizeof (decl_list_t));
  assert (dl != NULL);
  dl->n_children = 1;
  ast_node_t *ptr;

  for (ptr = ast; ptr->n_children > 1; ptr = ptr->children[0])
    dl->n_children++;

  dl->children = calloc (dl->n_children, sizeof (struct __decl *));
  assert (dl->children != NULL);

  for (ptr = ast; IS_DECLARATION_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  dl->children[0] = sem_declaration (ptr->children[0]);
  ptr = ptr->parent;
  for (int i = 1; ptr != NULL; ptr = ptr->parent, i++)
    dl->children[i] = sem_declaration (ptr->children[1]);

  return dl;
}
