#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
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

static void local_dot_create (void *Node, void *F);
static void do_term (struct compound_statement *node, FILE * f,
                     const char *token, int n_token);

struct compound_statement *
compound_statement_1 (void)
{
  struct compound_statement *buff =
    calloc (1, sizeof (struct compound_statement));
  assert (buff != NULL);
  buff->kind = NODE_COMPOUND_STATEMENT;
  buff->cs_kind = CS_EMPTY;

  buff->dot_create = local_dot_create;

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

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct compound_statement *node = Node;
  assert (node->kind == NODE_COMPOUND_STATEMENT);
  FILE *f = F;

  do_term (node, f, "{", 0);
  if (node->bil != NULL)
    {
      fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
               (unsigned long) node->bil);
      fprintf (f, "\t%lu [label=\"block item list\"]\n",
               (unsigned long) node->bil);
      node->bil->dot_create (node->bil, f);
    }
  do_term (node, f, "}", 1);
}

static void
do_term (struct compound_statement *node, FILE * f, const char *token,
         int n_token)
{
  assert (node != NULL);
  assert (f != NULL);
  assert (token != NULL);
  assert (n_token >= 0);

  fprintf (f, "\t%lu -> %lu%d;\n", (unsigned long) node,
           (unsigned long) node, n_token);
  fprintf (f, "\t%lu%d [label=\"%s\",shape=box,fontname=Courier]\n",
           (unsigned long) node, n_token, token);
}
