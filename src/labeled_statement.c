#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "labeled_statement.h"
#include "statement.h"
#include "constant_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

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

  return buff;
}

