#include <assert.h>
#include <stdlib.h>

#include "external_declaration.h"
#include "function_definition.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct external_declaration *
external_declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct external_declaration *buff =
    calloc (1, sizeof (struct external_declaration));
  assert (buff != NULL);
  buff->kind = NODE_EXTERNAL_DECLARATION;
  buff->child_kind = NODE_FUNCTION_DEFINITION;
  buff->fd = ptr;
  buff->fd->parent_kind = NODE_EXTERNAL_DECLARATION;
  buff->fd->parent = buff;

  return buff;
}

struct external_declaration *
external_declaration_2 (void *ptr)
{
  assert (ptr != NULL);

  struct external_declaration *buff =
    calloc (1, sizeof (struct external_declaration));
  assert (buff != NULL);
  buff->kind = NODE_EXTERNAL_DECLARATION;
  buff->child_kind = NODE_DECLARATION;
  buff->d = ptr;
  buff->d->parent_kind = NODE_EXTERNAL_DECLARATION;
  buff->d->parent = buff;

  return buff;
}

void
sem_external_declaration (struct external_declaration *buff)
{
  assert (buff != NULL);

  /*
   * TODO
   * Section 6.9, clauses 2 and 3 (difficult).
   * Beware clause 5
   */

  switch (buff->child_kind)
    {
    case NODE_FUNCTION_DEFINITION:
      sem_function_definition (buff->fd);
      break;

    case NODE_DECLARATION:
      sem_declaration (buff->d);
      break;

    default:
      ;                         /* BUG! */
    }
}
