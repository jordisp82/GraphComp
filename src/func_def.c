#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "func_def.h"
#include "sem_t.h"
#include "ast.h"
#include "compound_stmt.h"
#include "decl_specs.h"
#include "declarator.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static func_def_t *sem_func_def_kr (ast_node_t * ast);
static func_def_t *sem_func_def_iso (ast_node_t * ast);
static decltion_list_t *sem_decl_list (ast_node_t * ast);

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

  fd->decl_specs = sem_decl_specs (ast->children[0]);
  fd->decl_specs->parent_kind = PARENT_FUNC_DEF;
  fd->decl_specs->parent = fd;
  fd->declr = sem_declarator (ast->children[1]);
  fd->declr->parent_kind = PARENT_DECLARATION;
  fd->declr->parent = fd;
  fd->decln_list = sem_decl_list (ast->children[2]);
  fd->decln_list->parent_kind = PARENT_FUNC_DEF;
  fd->decln_list->parent = fd;
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

  fd->decl_specs = sem_decl_specs (ast->children[0]);
  fd->decl_specs->parent_kind = PARENT_FUNC_DEF;
  fd->decl_specs->parent = fd;
  fd->declr = sem_declarator (ast->children[1]);
  fd->declr = sem_declarator (ast->children[1]);
  fd->declr->parent_kind = PARENT_DECLARATION;
  fd->comp_stmt = sem_compound_stmt (ast->children[2]);
  fd->comp_stmt->parent_kind = PARENT_FUNC_DEF;
  fd->comp_stmt->parent = fd;

  return fd;
}

static decltion_list_t *
sem_decl_list (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_DECLARATION_LIST (ast->func_ptr));
  assert (ast->children != NULL && ast->n_children > 0);

  decltion_list_t *dl = calloc (1, sizeof (decltion_list_t));
  assert (dl != NULL);
  dl->node = ast;
  dl->n_declarations = 1;
  ast_node_t *ptr;

  for (ptr = ast; ptr->n_children > 1; ptr = ptr->children[0])
    dl->n_declarations++;

  dl->declarations =
    calloc (dl->n_declarations, sizeof (struct declaration *));
  assert (dl->declarations != NULL);

  for (ptr = ast; IS_DECLARATION_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  dl->declarations[0] = sem_declaration (ptr->children[0]);
  dl->declarations[0]->parent = dl;
  dl->declarations[0]->parent_kind = PARENT_DECLTION_LIST;
  ptr = ptr->parent;
  for (int i = 1; ptr != NULL; ptr = ptr->parent, i++)
    {
      dl->declarations[i] = sem_declaration (ptr->children[1]);
      dl->declarations[i]->parent = dl;
      dl->declarations[i]->parent_kind = PARENT_DECLTION_LIST;
    }

  return dl;
}
