#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "type_name.h"
#include "specifier_qualifier_list.h"
#include "abstract_declarator.h"
#include "postfix_expression.h"
#include "unary_expression.h"
#include "cast_expression.h"
#include "atomic_type_specifier.h"
#include "alignment_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct type_name *
type_name_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_name *buff = calloc (1, sizeof (struct type_name));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_NAME;
  buff->sql = ptr1;
  buff->adlr = ptr2;
  buff->sql->parent_kind = buff->adlr->parent_kind = NODE_TYPE_NAME;
  buff->sql->parent = buff->adlr->parent = buff;

  return buff;
}

struct type_name *
type_name_2 (void *ptr)
{
  assert (ptr != NULL);

  struct type_name *buff = calloc (1, sizeof (struct type_name));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_NAME;
  buff->sql = ptr;
  buff->sql->parent_kind = NODE_TYPE_NAME;
  buff->sql->parent = buff;

  return buff;
}

void
set_type_name_scope (struct type_name *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TYPE_NAME);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_POSTFIX_EXPRESSION:
        set_postfix_expression_scope (buff->parent);
        buff->scope = ((struct postfix_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct postfix_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_UNARY_EXPRESSION:
        set_unary_expression_scope (buff->parent);
        buff->scope = ((struct unary_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct unary_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_CAST_EXPRESSION:
        set_cast_expression_scope (buff->parent);
        buff->scope = ((struct cast_expression *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct cast_expression *) (buff->parent))->scope_kind;
        break;

      case NODE_ATOMIC_TYPE_SPECIFIER:
        set_atomic_specifier_scope (buff->parent);
        buff->scope =
          ((struct atomic_type_specifier *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct atomic_type_specifier *) (buff->parent))->scope_kind;
        break;

      case NODE_ALIGNMENT_SPECIFIER:
        set_alignment_specifier_scope (buff->parent);
        buff->scope = ((struct alignment_specifier *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct alignment_specifier *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
