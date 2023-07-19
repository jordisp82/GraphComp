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

static void cs_create_symtable (struct compound_statement *buff);
static void cs_create_symbol (struct compound_statement *buff);

struct compound_statement *
compound_statement_1 (void)
{
  struct compound_statement *buff =
    calloc (1, sizeof (struct compound_statement));
  assert (buff != NULL);
  buff->kind = NODE_COMPOUND_STATEMENT;
  buff->cs_kind = CS_EMPTY;
  buff->create_symtable = cs_create_symtable;
  buff->create_symbol = cs_create_symbol;

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
  buff->create_symtable = cs_create_symtable;
  buff->create_symbol = cs_create_symbol;

  return buff;
}

static void
cs_create_symtable (struct compound_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_COMPOUND_STATEMENT);

  buff->sym_table = calloc (1, sizeof (struct symtable));
  assert (buff->sym_table != NULL);
  buff->sym_table->node = buff;
  buff->sym_table->node_kind = NODE_COMPOUND_STATEMENT;

  switch (buff->parent_kind)
    {
    case NODE_STATEMENT:
      buff->sym_table->parent =
        ((struct statement *) (buff->parent))->sym_table;
      break;

    case NODE_FUNCTION_DEFINITION:
      buff->sym_table->parent =
        ((struct function_definition *) (buff->parent))->sym_table;
      break;

    default:
      return;                   /* BUG! */
    }

  int n = buff->sym_table->parent->n_children;
  struct symtable **new_ch = calloc (n + 1, sizeof (struct symtable *));
  assert (new_ch != NULL);
  for (int i = 0; i < n; i++)
    new_ch[i] = buff->sym_table->parent->children[i];
  new_ch[n] = buff->sym_table;
  free (buff->sym_table->parent->children);
  buff->sym_table->parent->children = new_ch;
  buff->sym_table->parent->n_children++;

  if (buff->bil != NULL)
    buff->bil->create_symtable (buff->bil);
  buff->sym_table->ord = buff->sym_table->tags = NULL;
}

static void
cs_create_symbol (struct compound_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_COMPOUND_STATEMENT);
  assert (buff->sym_table != NULL);

  if (buff->bil != NULL)
    buff->bil->create_symbol (buff->bil);
}
