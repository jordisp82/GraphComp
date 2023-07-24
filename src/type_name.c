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

static void tn_create_symtable (struct type_name *buff);
static void tn_create_symbol (struct type_name *buff);

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
  buff->create_symtable = tn_create_symtable;
  buff->create_symbol = tn_create_symbol;

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
  buff->create_symtable = tn_create_symtable;
  buff->create_symbol = tn_create_symbol;

  return buff;
}

static void
tn_create_symtable (struct type_name *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TYPE_NAME);

  switch (buff->parent_kind)
    {
    case NODE_POSTFIX_EXPRESSION:
      buff->sym_table =
        ((struct postfix_expression *) (buff->parent))->sym_table;
      break;

    case NODE_UNARY_EXPRESSION:
      buff->sym_table =
        ((struct unary_expression *) (buff->parent))->sym_table;
      break;

    case NODE_CAST_EXPRESSION:
      buff->sym_table =
        ((struct cast_expression *) (buff->parent))->sym_table;
      break;

    case NODE_ATOMIC_TYPE_SPECIFIER:
      buff->sym_table =
        ((struct atomic_type_specifier *) (buff->parent))->sym_table;
      break;

    case NODE_ALIGNMENT_SPECIFIER:
      buff->sym_table =
        ((struct alignment_specifier *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  if (buff->sql != NULL)
    buff->sql->create_symtable (buff->sql);
  if (buff->adlr != NULL)
    buff->adlr->create_symtable (buff->adlr);
}

static void
tn_create_symbol (struct type_name *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TYPE_NAME);
  assert (buff->sym_table != NULL);

  if (buff->sql != NULL)
    buff->sql->create_symbol (buff->sql);
  if (buff->adlr != NULL)
    buff->adlr->create_symbol (buff->adlr);
}
