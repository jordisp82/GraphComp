#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "dir_declr.h"
#include "ast.h"
#include "declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_direct_declr_ident (direct_declr_t * ddr, ast_node_t * ast);
static void sem_direct_declr_declr (direct_declr_t * ddr, ast_node_t * ast);
static void sem_direct_declr_array (direct_declr_t * ddr, ast_node_t * ast);
static void sem_direct_declr_function (direct_declr_t * ddr,
                                       ast_node_t * ast);
static void sem_param_type_list (direct_declr_t * ddr, ast_node_t * ast);

direct_declr_t *
sem_direct_declarator (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_DIRECT_DECLARATOR (ast->func_ptr));
  assert (ast->children != NULL || ast->n_children == 0);

  direct_declr_t *ddr = calloc (1, sizeof (direct_declr_t));
  assert (ddr != NULL);

  if (ast->func_ptr == direct_declarator_1)
    sem_direct_declr_ident (ddr, ast);
  else if (ast->func_ptr == direct_declarator_2)
    sem_direct_declr_declr (ddr, ast);
  else if (ast->func_ptr == direct_declarator_3
           || ast->func_ptr == direct_declarator_4
           || ast->func_ptr == direct_declarator_5
           || ast->func_ptr == direct_declarator_6
           || ast->func_ptr == direct_declarator_7
           || ast->func_ptr == direct_declarator_8
           || ast->func_ptr == direct_declarator_9
           || ast->func_ptr == direct_declarator_10
           || ast->func_ptr == direct_declarator_11)
    sem_direct_declr_array (ddr, ast);
  else if (ast->func_ptr == direct_declarator_12
           || ast->func_ptr == direct_declarator_13
           || ast->func_ptr == direct_declarator_14)
    sem_direct_declr_function (ddr, ast);

  return ddr;
}

static void
sem_direct_declr_ident (direct_declr_t * ddr, ast_node_t * ast)
{
  assert (ddr != NULL);
  assert (ast != NULL);
  assert (IS_DIRECT_DECLARATOR (ast->func_ptr));

  ddr->kind = DIR_DECLR_IDENT;
  ddr->ddeclr.ident.id = strdup (ast->data);
  assert (ddr->ddeclr.ident.id != NULL);
}

static void
sem_direct_declr_declr (direct_declr_t * ddr, ast_node_t * ast)
{
  assert (ddr != NULL);
  assert (ast != NULL);
  assert (IS_DIRECT_DECLARATOR (ast->func_ptr));
  assert (ast->children != NULL);

  ddr->kind = DIR_DECLR_DECLR;
  ddr->ddeclr.declr = sem_declarator (ast->children[0]);
}

static void
sem_direct_declr_array (direct_declr_t * ddr, ast_node_t * ast)
{
  assert (ddr != NULL);
  assert (ast != NULL);
  assert (IS_DIRECT_DECLARATOR (ast->func_ptr));
  assert (ast->children != NULL);

  ddr->kind = DIR_DECLR_ARRAY;

  /* TODO */
}

static void
sem_direct_declr_function (direct_declr_t * ddr, ast_node_t * ast)
{
  assert (ddr != NULL);
  assert (ast != NULL);
  assert (IS_DIRECT_DECLARATOR (ast->func_ptr));
  assert (ast->children != NULL);

  ddr->kind = DIR_DECLR_FUNCTION;
  ddr->ddeclr.function.ddeclr = NULL;
  ddr->ddeclr.function.ptlist = NULL;

  if (ast->func_ptr == direct_declarator_13)
    return;

  if (ast->func_ptr == direct_declarator_14)
    return;                     /* TODO it's really a K&R definition */

  ddr->ddeclr.function.ddeclr = sem_direct_declarator (ast->children[0]);
  sem_param_type_list (ddr, ast->children[1]);
}

static void
sem_param_type_list (direct_declr_t * ddr, ast_node_t * ast)
{
  assert (ddr != NULL);
  assert (ast != NULL);
  assert (IS_PARAMETER_TYPE_LIST (ast->func_ptr));
  assert (ast->children != NULL);

  ddr->ddeclr.function.ptlist = calloc (1, sizeof (param_type_list_t));
  assert (ddr->ddeclr.function.ptlist != NULL);

  if (ast->func_ptr == parameter_type_list_1)
    ddr->ddeclr.function.ptlist->is_variadic = 1;

  ddr->ddeclr.function.ptlist->n_params = 1;
  ast_node_t *ptr;

  for (ptr = ast->children[0]; ptr->n_children > 1; ptr = ptr->children[0])
    ddr->ddeclr.function.ptlist->n_params++;

  ddr->ddeclr.function.ptlist->params =
    calloc (ddr->ddeclr.function.ptlist->n_params,
            sizeof (struct __paramdecl *));
  assert (ddr->ddeclr.function.ptlist->params != NULL);

  /* TODO */
}
