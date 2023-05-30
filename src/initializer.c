#include <assert.h>
#include <stdlib.h>

#include "initializer.h"
#include "initializer_list.h"
#include "assignment_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct initializer *
initializer_1 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_LIST;
  buff->il = ptr;
  buff->il->parent_kind = NODE_INITIALIZER;
  buff->il->parent = buff;

  return buff;
}

struct initializer *
initializer_2 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_LIST;
  buff->il = ptr;
  buff->il->parent_kind = NODE_INITIALIZER;
  buff->il->parent = buff;

  return buff;
}

struct initializer *
initializer_3 (void *ptr)
{
  assert (ptr != NULL);

  struct initializer *buff = calloc (1, sizeof (struct initializer));
  assert (buff != NULL);
  buff->kind = NODE_INITIALIZER;
  buff->child_kind = IN_ASS_EXPR;
  buff->ae = ptr;
  buff->ae->parent_kind = NODE_INITIALIZER;
  buff->ae->parent = buff;

  return buff;
}

void
set_initializer_scope (struct initializer *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INITIALIZER);

  switch (buff->parent_kind)
    {
    case NODE_INIT_DECLARATOR:
      break;

    case NODE_INITIALIZER_LIST:
      break;

    default:
      ;                         /* BUG! */
    }
}
