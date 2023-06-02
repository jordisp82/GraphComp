#include <assert.h>
#include <stdlib.h>

#include "initializer.h"
#include "initializer_list.h"
#include "assignment_expression.h"
#include "init_declarator.h"
#include "initializer_list.h"

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

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_INIT_DECLARATOR:
        set_init_declarator_scope (buff->parent);
        buff->scope = ((struct init_declarator *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct init_declarator *) (buff->parent))->scope_kind;
        break;

      case NODE_INITIALIZER_LIST:
        set_initializer_list_scope (buff->parent);
        buff->scope = ((struct initializer_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct initializer_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
