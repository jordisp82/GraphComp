#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "func_def.h"
#include "sem_t.h"
#include "ast.h"
#include "compound_stmt.h"

#if 0
#include "decl_specs.h"
#include "declarator.h"
#include "declaration.h"
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

static func_def_t *sem_func_def_kr (ast_node_t * ast);
static func_def_t *sem_func_def_iso (ast_node_t * ast);
#if 0
static decl_list_t *sem_decl_list (ast_node_t * ast);
#endif

func_def_t *
sem_func_def (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_FUNCTION_DEFINITION (ast->func_ptr));
  assert (ast->children != NULL);

  if (ast->func_ptr == function_definition_1)   /* K&R-sytle definition */
    return sem_func_def_kr (ast);
  else if (ast->func_ptr == function_definition_2)      /* ANSI/ISO-style definition */
    return sem_func_def_iso (ast);
  else
    return NULL;                /* unreachable, in theory */
}

static func_def_t *
sem_func_def_kr (ast_node_t * ast)
{
  assert (ast->n_children == 4);

  func_def_t *fd = calloc (1, sizeof (func_def_t));
  assert (fd != NULL);

#if 0
  fd->decl_specs = sem_decl_specs (ast->children[0]);
  fd->declarator = sem_declarator (ast->children[1]);
  fd->decl_list = sem_decl_list (ast->children[2]);
#endif
  fd->comp_stmt = sem_compound_stmt (ast->children[3]);
  fd->comp_stmt->parent_kind = PARENT_FUNC_DEF;
  fd->comp_stmt->parent = fd;

  return fd;
}

static func_def_t *
sem_func_def_iso (ast_node_t * ast)
{
  assert (ast->n_children == 3);
  assert (IS_COMPOUND_STATEMENT (ast->children[2]->func_ptr));

  func_def_t *fd = calloc (1, sizeof (func_def_t));
  assert (fd != NULL);

#if 0
  fd->decl_specs = sem_decl_specs (ast->children[0]);
  fd->declarator = sem_declarator (ast->children[1]);
  fd->compound_stmt = sem_compound_stmt (ast->children[2]);
#endif

  return fd;
}

#if 0
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
#endif
