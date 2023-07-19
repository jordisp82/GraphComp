#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "labeled_statement.h"
#include "statement.h"
#include "constant_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ls_create_symtable (struct labeled_statement *buff);
static void ls_create_symbol (struct labeled_statement *buff);

struct labeled_statement *
labeled_statement_1 (const char *str, void *ptr2)
{
  assert (str != NULL);
  assert (ptr2 != NULL);

  struct labeled_statement *buff =
    calloc (1, sizeof (struct labeled_statement));
  assert (buff != NULL);
  buff->kind = NODE_LABELED_STATEMENT;
  buff->ls_kind = LABEL_IDENTIFIER;
  buff->id = strdup (str);
  assert (buff->id != NULL);
  buff->s = ptr2;
  buff->s->parent_kind = NODE_LABELED_STATEMENT;
  buff->s->parent = buff;
  buff->create_symtable = ls_create_symtable;
  buff->create_symbol = ls_create_symbol;

  return buff;
}

struct labeled_statement *
labeled_statement_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct labeled_statement *buff =
    calloc (1, sizeof (struct labeled_statement));
  assert (buff != NULL);
  buff->kind = NODE_LABELED_STATEMENT;
  buff->ls_kind = LABEL_CASE;
  buff->ce = ptr1;
  buff->s = ptr2;
  buff->ce->parent_kind = buff->s->parent_kind = NODE_LABELED_STATEMENT;
  buff->ce->parent = buff->s->parent = buff;
  buff->create_symtable = ls_create_symtable;
  buff->create_symbol = ls_create_symbol;

  return buff;
}

struct labeled_statement *
labeled_statement_3 (void *ptr)
{
  assert (ptr != NULL);

  struct labeled_statement *buff =
    calloc (1, sizeof (struct labeled_statement));
  assert (buff != NULL);
  buff->kind = NODE_LABELED_STATEMENT;
  buff->ls_kind = LABEL_DEFAULT;
  buff->s = ptr;
  buff->s->parent_kind = NODE_LABELED_STATEMENT;
  buff->s->parent = buff;
  buff->create_symtable = ls_create_symtable;
  buff->create_symbol = ls_create_symbol;

  return buff;
}

static void
ls_create_symtable (struct labeled_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LABELED_STATEMENT);

  buff->sym_table = ((struct statement *) (buff->parent))->sym_table;
  buff->s->create_symtable (buff->s);
  switch (buff->ls_kind)
    {
    case LABEL_IDENTIFIER:
    case LABEL_DEFAULT:
      break;

    case LABEL_CASE:
      buff->ce->create_symtable (buff->ce);
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
ls_create_symbol (struct labeled_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_LABELED_STATEMENT);
  assert (buff->sym_table != NULL);

  buff->s->create_symbol (buff->s);
  switch (buff->ls_kind)
    {
    case LABEL_IDENTIFIER:
    case LABEL_DEFAULT:
      break;

    case LABEL_CASE:
      buff->ce->create_symbol (buff->ce);
      break;

    default:
      ;                         /* BUG! */
    }
}
