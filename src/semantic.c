#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "ast.h"
#include "semantic.h"
#include "sem_t.h"
#include "func_def.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static extern_decl_t *sem_extern_decl (ast_node_t * ast);

void
semantic_analysis (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (ast->children != NULL);
  assert (IS_TRANSLATION_UNIT (ast->func_ptr));

  /*
   * We expect this function to be called
   * only for translation units.
   * Translation units are a bunch of
   * external declarations.
   */

  transl_unit_t *tu = calloc (1, sizeof (transl_unit_t));
  assert (tu != NULL);
  tu->n_children = 1;
  tu->node = ast;
  ast_node_t *ptr;

  for (ptr = ast; ptr->n_children > 1; ptr = ptr->children[0])
    tu->n_children++;

  tu->children = calloc (tu->n_children, sizeof (extern_decl_t *));
  assert (tu->children != NULL);

  for (ptr = ast; IS_TRANSLATION_UNIT (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  tu->children[0] = sem_extern_decl (ptr->children[0]);
  ptr = ptr->parent;
  for (int i = 1; ptr != NULL; ptr = ptr->parent, i++)
    tu->children[i] = sem_extern_decl (ptr->children[1]);

  for (int i = 0; i < tu->n_children; i++)
    tu->children[i]->parent = tu;
}

static extern_decl_t *
sem_extern_decl (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_EXTERNAL_DECLARATION (ast->func_ptr));
  assert (ast->children != NULL);

  extern_decl_t *ed = calloc (1, sizeof (extern_decl_t));
  assert (ed != NULL);

  if (IS_FUNCTION_DEFINITION (ast->children[0]->func_ptr))
    {
      ed->kind = EXTDEF_FUNC_DEF;
      ed->func_def = sem_func_def (ast->children[0]);
      ed->func_def->parent = ed;
      ed->node = ast;
    }
  else if (IS_DECLARATION (ast->children[0]->func_ptr))
    {
      ed->kind = EXTDEF_DECL;
      //ed->decltion = sem_declaration (ast->children[0]);
      ed->node = ast;
    }
  /* else abort */

  return ed;
}
