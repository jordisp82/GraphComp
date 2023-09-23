#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "compound_statement.h"
#include "block_item_list.h"
#include "block_item.h"
#include "declaration.h"
#include "statement.h"
#include "function_definition.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct compound_statement *
compound_statement_1 (void)
{
  struct compound_statement *buff =
    calloc (1, sizeof (struct compound_statement));
  assert (buff != NULL);
  buff->kind = NODE_COMPOUND_STATEMENT;
  buff->cs_kind = CS_EMPTY;

  return buff;
}

struct compound_statement *
compound_statement_2 (void *ptr)
{
  assert (ptr != NULL);

  struct compound_statement *buff =
    calloc (1, sizeof (struct compound_statement));
  assert (buff != NULL);
  buff->kind = NODE_COMPOUND_STATEMENT;
  buff->cs_kind = CS_BLOCK_ITEM_LIST;
  buff->bil = ptr;
  buff->bil->parent_kind = NODE_COMPOUND_STATEMENT;
  buff->bil->parent = buff;

  return buff;
}
