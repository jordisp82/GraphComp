#include <assert.h>
#include <stdlib.h>

#include "alignment_specifier.h"
#include "type_name.h"
#include "constant_expression.h"
#include "declaration_specifiers.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void as_create_symtable (struct alignment_specifier *buff);

struct alignment_specifier *
alignment_specifier_1 (void *ptr)
{
  assert (ptr != NULL);

  struct alignment_specifier *buff =
    calloc (1, sizeof (struct alignment_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ALIGNMENT_SPECIFIER;
  buff->a_kind = ALIGN_TYPE_NAME;
  buff->tn = ptr;
  buff->tn->parent_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->tn->parent = buff;
  buff->create_symtable = as_create_symtable;

  return buff;
}

struct alignment_specifier *
alignment_specifier_2 (void *ptr)
{
  assert (ptr != NULL);

  struct alignment_specifier *buff =
    calloc (1, sizeof (struct alignment_specifier));
  assert (buff != NULL);
  buff->kind = NODE_ALIGNMENT_SPECIFIER;
  buff->a_kind = ALIGN_CONST_EXPR;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->expr->parent = buff;
  buff->create_symtable = as_create_symtable;

  return buff;
}

static void
as_create_symtable (struct alignment_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ALIGNMENT_SPECIFIER);

  buff->sym_table =
    ((struct declaration_specifiers *) (buff->parent))->sym_table;
  if (buff->tn != NULL)
    buff->tn->create_symtable (buff->tn);
  if (buff->expr != NULL)
    buff->expr->create_symtable (buff->expr);
}

#if 0
void
set_alignment_specifier_scope (struct alignment_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ALIGNMENT_SPECIFIER);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_DECLARATION_SPECIFIERS:
        set_declaration_specifiers_scope (buff->parent);
        buff->scope =
          ((struct declaration_specifiers *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct declaration_specifiers *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}
#endif
