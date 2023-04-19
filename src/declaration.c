#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "declaration.h"
#include "ast.h"
#include "decl_specs.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_init_decl_list (ast_node_t * ast);

void
sem_declarations (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_DECLARATION (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  if (ast->func_ptr == declaration_3)
    return;                     /* fuck off static asserts, at least for now */

  /*
   * two options:
   * (a) declaration-specifiers ;
   * (b) declaration-specifiers init-declarator-list ;
   * I'm quite sure that (a) is useless, but...
   */

  if (ast->func_ptr == declaration_1)
    if (IS_TRANSLATION_UNIT (ast->parent->func_ptr)
        || IS_BLOCK_ITEM (ast->parent->func_ptr))
      return;                   /* useless declaration */

  /* ok, let's assume that at this point we are "declaration_2" */

  assert (IS_DECLARATION_SPECS (ast->children[0]->func_ptr));
  assert (IS_INIT_DECLARATOR_LIST (ast->children[1]->func_ptr));

  sem_decl_specs (ast->children[0]);
  sem_init_decl_list (ast->children[1]);
}

static void
sem_init_decl_list (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_INIT_DECLARATOR_LIST (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);
}
