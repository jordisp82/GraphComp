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
static void as_create_symbol (struct alignment_specifier *buff);

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
  buff->create_symbol = as_create_symbol;

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
  buff->create_symbol = as_create_symbol;

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

static void
as_create_symbol (struct alignment_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ALIGNMENT_SPECIFIER);
  assert (buff->sym_table != NULL);

  switch (buff->a_kind)
    {
    case ALIGN_TYPE_NAME:
      buff->tn->create_symbol (buff->tn);
      break;

    case ALIGN_CONST_EXPR:
      buff->expr->create_symbol (buff->expr);
      break;

    default:
      ;                         /* BUG! */
    }
}
