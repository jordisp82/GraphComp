#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "declaration.h"
#include "sem_t.h"
#include "ast.h"

#if 0
#include "decl_specs.h"
#include "declarator.h"
#include "ass_expr.h"
#include "cond_expr.h"
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

#if 0
static void sem_init_declr_list (declaration_t * decl, ast_node_t * ast);
static init_declr_t *sem_init_declr (ast_node_t * ast);
static initializer_t *sem_initializer (ast_node_t * ast);
static init_list_t *sem_init_list (ast_node_t * ast);
static init_block_t *sem_init_block1 (ast_node_t * ast);
static init_block_t *sem_init_block2 (ast_node_t * ast);
static designation_t *sem_designation (ast_node_t * ast);
static designator_t *sem_designator (ast_node_t * ast);
#endif

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

  /* TODO
     decl->decl_specs = sem_decl_specs (ast->children[0]);
     if (ast->func_ptr == declaration_2)
     sem_init_declr_list (decl, ast);
   */

  return decl;
}

#if 0
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
  if (ast->n_children > 1)
    idr->initzr = sem_initializer (ast->children[1]);

  return idr;
}

static initializer_t *
sem_initializer (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_INITIALIZER (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  initializer_t *iz = calloc (1, sizeof (initializer_t));
  assert (iz != NULL);

  if (ast->func_ptr == initializer_1 || ast->func_ptr == initializer_2)
    {
      iz->kind = INITZR_LIST;
      iz->child.init_list = sem_init_list (ast->children[0]);
    }
  else if (ast->func_ptr == initializer_3)
    {
      iz->kind = INITZR_EXPR;
      iz->child.expr = sem_ass_expr (ast->children[0]);
    }

  return iz;
}

static init_list_t *
sem_init_list (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_INITIALIZER_LIST (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  init_list_t *il = calloc (1, sizeof (init_list_t));
  assert (il != NULL);
  il->n_init_blocks = 1;
  ast_node_t *ptr;

  for (ptr = ast; IS_INITIALIZER_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0])
    il->n_init_blocks++;

  il->init_blocks = calloc (il->n_init_blocks, sizeof (init_block_t *));
  assert (il->init_blocks != NULL);

  for (ptr = ast; IS_INITIALIZER_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  il->init_blocks[0] = sem_init_block1 (ptr);
  ptr = ptr->parent;
  for (int i = 1; ptr != NULL; ptr = ptr->parent, i++)
    il->init_blocks[i] = sem_init_block2 (ptr);

  return il;
}

static init_block_t *
sem_init_block1 (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  init_block_t *ib = calloc (1, sizeof (init_block_t));
  assert (ib != NULL);

  if (ast->children[0]->func_ptr == designation)
    {
      ib->design = sem_designation (ast->children[0]);
      ib->initializer = sem_initializer (ast->children[1]);
    }
  else if (IS_INITIALIZER (ast->children[0]->func_ptr))
    ib->initializer = sem_initializer (ast->children[0]);

  return ib;
}

static init_block_t *
sem_init_block2 (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  init_block_t *ib = calloc (1, sizeof (init_block_t));
  assert (ib != NULL);

  if (ast->children[1]->func_ptr == designation)
    {
      ib->design = sem_designation (ast->children[1]);
      ib->initializer = sem_initializer (ast->children[2]);
    }
  else if (IS_INITIALIZER (ast->children[1]->func_ptr))
    ib->initializer = sem_initializer (ast->children[1]);

  return ib;
}

static designation_t *
sem_designation (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (ast->func_ptr == designation);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  designation_t *ds = calloc (1, sizeof (designation_t));
  assert (ds != NULL);
  ds->n_designators = 1;
  ast_node_t *ptr;

  for (ptr = ast; IS_DESIGNATOR_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0])
    ds->n_designators++;

  ds->designators = calloc (ds->n_designators, sizeof (designator_t *));
  assert (ds->designators != NULL);

  for (ptr = ast; IS_DESIGNATOR_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  ds->designators[0] = sem_designator (ptr->children[0]);
  ptr = ptr->parent;
  for (int i = 1; ptr != NULL; ptr = ptr->parent, i++)
    ds->designators[i] = sem_designator (ptr->children[1]);

  return ds;
}

static designator_t *
sem_designator (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_DESIGNATOR (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  designator_t *ds = calloc (1, sizeof (designator_t));
  assert (ds != NULL);

  if (ast->func_ptr == designator_1)
    ds->const_expr = sem_cond_expr (ast->children[0]);
  else if (ast->func_ptr == designator_2)
    ds->id = strdup (ast->data);

  return ds;
}
#endif
