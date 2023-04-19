#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>

#include "semantic.h"
#include "ast.h"
#include "func_def.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_extern_decl (ast_node_t * ast);

void
semantic_analysis (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /*
   * We expect this function to be called
   * only for translation units.
   */

  if (IS_TRANSLATION_UNIT (ast->func_ptr) == 0)
    return;

  for (int i = 0; i < ast->n_children; i++)
    if (IS_TRANSLATION_UNIT (ast->children[i]->func_ptr))
      semantic_analysis (ast->children[i]);
    else if (IS_EXTERNAL_DECLARATION (ast->children[i]->func_ptr))
      sem_extern_decl (ast->children[i]);
}

static void
sem_extern_decl (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_EXTERNAL_DECLARATION (ast->func_ptr));
  assert (ast->children != NULL || ast->n_children == 0);

  if (IS_FUNCTION_DEFINITION (ast->children[0]->func_ptr))
    sem_func_def (ast->children[0]);
  else if (IS_DECLARATION (ast->children[0]->func_ptr))
    sem_declarations (ast->children[0]);
}
