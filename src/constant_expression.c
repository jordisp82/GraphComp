#include <assert.h>
#include <stdlib.h>

#include "constant_expression.h"
#include "conditional_expression.h"
#include "labeled_statement.h"
#include "static_assert_declaration.h"
#include "alignment_specifier.h"
#include "struct_declarator.h"
#include "enumerator.h"
#include "designator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct constant_expression *
constant_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct constant_expression *buff =
    calloc (1, sizeof (struct constant_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT_EXPRESSION;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_CONSTANT_EXPRESSION;
  buff->expr->parent = buff;

  return buff;
}

void
set_const_expression_scope (struct constant_expression *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CONSTANT_EXPRESSION);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_STRUCT_DECLARATOR:
        set_struct_declarator_scope (buff->parent);
        buff->scope = ((struct struct_declarator *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct struct_declarator *) (buff->parent))->scope_kind;
        break;

      case NODE_ENUMERATOR:
        set_enumerator_scope (buff->parent);
        buff->scope = ((struct enumerator *) (buff->parent))->scope;
        buff->scope_kind = ((struct enumerator *) (buff->parent))->scope_kind;
        break;

      case NODE_ALIGNMENT_SPECIFIER:
        set_alignment_specifier_scope (buff->parent);
        buff->scope = ((struct alignment_specifier *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct alignment_specifier *) (buff->parent))->scope_kind;
        break;

      case NODE_DESIGNATOR:
        set_designator_scope (buff->parent);
        buff->scope = ((struct designator *) (buff->parent))->scope;
        buff->scope_kind = ((struct designator *) (buff->parent))->scope_kind;
        break;

      case NODE_STATIC_ASSERT_DECLARATION:
        set_static_assert_scope (buff->parent);
        buff->scope =
          ((struct static_assert_declaration *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct static_assert_declaration *) (buff->parent))->scope_kind;
        break;

      case NODE_LABELED_STATEMENT:
        set_labeled_stmt_scope (buff->parent);
        buff->scope = ((struct labeled_statement *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct labeled_statement *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG */
      }
}
