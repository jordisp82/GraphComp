#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>

#include "func_def.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

void
sem_func_def (ast_node_t * ast)
{
  assert (ast != NULL);

  if (ast->func_ptr == function_definition_1)
    return;                     /* for now we reject K&R-style function definitions */

  /*
   * children must be:
   * declaration-specifiers
   * declarator
   * compound-statement
   */

  /* TODO */
}
