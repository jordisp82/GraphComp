#include <assert.h>
#include <stdlib.h>

#include "argument_expression_list.h"
#include "assignment_expression.h"
#include "postfix_expression.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void ael_create_symtable (struct argument_expression_list *buff);
static void ael_create_symbol (struct argument_expression_list *buff);

struct argument_expression_list *
argument_expression_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct argument_expression_list *buff =
    calloc (1, sizeof (struct argument_expression_list));
  assert (buff != NULL);
  buff->kind = NODE_ARGUMENT_EXPRESSION_LIST;
  buff->first = calloc (1, sizeof (struct ael_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ass = ptr;
  buff->first->ass->parent_kind = NODE_ARGUMENT_EXPRESSION_LIST;
  buff->first->ass->parent = buff;
  buff->create_symtable = ael_create_symtable;
  buff->create_symbol = ael_create_symbol;

  return buff;
}

struct argument_expression_list *
argument_expression_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct argument_expression_list *buff = ptr1;
  struct assignment_expression *ass = ptr2;

  buff->last->next = calloc (1, sizeof (struct ael_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ass = ass;
  ass->parent_kind = NODE_ARGUMENT_EXPRESSION_LIST;
  ass->parent = buff;
  buff->create_symtable = ael_create_symtable;
  buff->create_symbol = ael_create_symbol;

  return buff;
}

static void
ael_create_symtable (struct argument_expression_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ARGUMENT_EXPRESSION_LIST);

  switch (buff->parent_kind)
    {
    case NODE_ARGUMENT_EXPRESSION_LIST:
      buff->sym_table =
        ((struct argument_expression_list *) (buff->parent))->sym_table;
      break;

    case NODE_POSTFIX_EXPRESSION:
      buff->sym_table =
        ((struct postfix_expression *) (buff->parent))->sym_table;
      break;

    default:
      ;                         /* BUG! */
    }

  for (struct ael_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->ass->create_symtable (ptr->ass);
}

static void
ael_create_symbol (struct argument_expression_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_ARGUMENT_EXPRESSION_LIST);
  assert (buff->sym_table != NULL);

  for (struct ael_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    ptr->ass->create_symbol (ptr->ass);
}
