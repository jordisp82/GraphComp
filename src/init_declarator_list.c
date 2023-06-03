#include <assert.h>
#include <stdlib.h>

#include "init_declarator_list.h"
#include "init_declarator.h"
#include "declaration.h"
#include "declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct init_declarator_list *
init_declarator_list_1 (void *ptr)
{
  assert (ptr != NULL);

  struct init_declarator_list *buff =
    calloc (1, sizeof (struct init_declarator_list));
  assert (buff != NULL);
  buff->kind = NODE_INIT_DECLARATOR_LIST;
  buff->first = calloc (1, sizeof (struct idl_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->id = ptr;
  buff->first->id->parent_kind = NODE_INIT_DECLARATOR_LIST;
  buff->first->id->parent = buff;

  return buff;
}

struct init_declarator_list *
init_declarator_list_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct init_declarator_list *buff = ptr1;
  struct init_declarator *id = ptr2;

  buff->last->next = calloc (1, sizeof (struct idl_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->id = id;
  id->parent_kind = NODE_INIT_DECLARATOR_LIST;
  id->parent = buff;

  return buff;
}

int
create_symbols_for_init_declarator_list (struct init_declarator_list *buff,
                                         symbol_t *** syms)
{
  assert (buff != NULL);
  assert (syms != NULL);

  int n = 0;
  for (struct idl_node * ptr = buff->first; ptr != NULL;
       n++, ptr = ptr->next);

  symbol_t **aux = calloc (n, sizeof (symbol_t *));
  assert (aux != NULL);

  int i = 0;
  for (struct idl_node * ptr = buff->first; ptr != NULL; i++, ptr = ptr->next)
    aux[i] = create_symbol_from_init_declarator (ptr->id);
  *syms = aux;

  return n;
}

void
set_init_declarator_list_scope (struct init_declarator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INIT_DECLARATOR_LIST);

  if (buff->scope == NULL || buff->scope_kind == NODE_UNDEFINED)
    switch (buff->parent_kind)
      {
      case NODE_DECLARATION:
        set_declaration_scope (buff->parent);
        buff->scope = ((struct declaration *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct declaration *) (buff->parent))->scope_kind;
        break;

      case NODE_INIT_DECLARATOR_LIST:
        set_init_declarator_list_scope (buff->parent);
        buff->scope = ((struct init_declarator_list *) (buff->parent))->scope;
        buff->scope_kind =
          ((struct init_declarator_list *) (buff->parent))->scope_kind;
        break;

      default:
        ;                       /* BUG! */
      }
}

void
fill_init_symtable_idl (struct init_declarator_list *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_INIT_DECLARATOR_LIST);

  for (struct idl_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    fill_in_symtable_init_declarator (ptr->id);
}
