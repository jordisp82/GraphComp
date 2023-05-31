#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "declaration.h"
#include "declaration_specifiers.h"
#include "init_declarator_list.h"
#include "static_assert_declaration.h"
#include "external_declaration.h"
#include "block_item.h"
#include "block_item_list.h"
#include "declaration_list.h"
#include "function_definition.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static int create_symbol_one_for_ds (struct declaration *buff,
                                     symbol_t *** syms);
static int create_symbols_for_list (struct declaration *buff,
                                    symbol_t *** syms);
static void create_symbol_adjust_scope (struct declaration *buff,
                                        symbol_t * sym);
void set_declaration_scope (struct declaration *buff);

struct declaration *
declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr;
  buff->ds->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff;

  return buff;
}

struct declaration *
declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr1;
  buff->idl = ptr2;
  buff->ds->parent_kind = buff->idl->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff->idl->parent = buff;

  if (look_for_typedef (buff->ds) == 1)
    register_ids_as_typedef (buff->idl);

  return buff;
}

struct declaration *
declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->sad = ptr;
  buff->sad->parent_kind = NODE_DECLARATION;
  buff->sad->parent = buff;

  return buff;
}

int
create_symbols_from_declaration (struct declaration *buff, symbol_t *** syms)
{
  assert (buff != NULL);
  assert (syms != NULL);

  /*
   * No symbols for static asssert declarations.
   */
  if (buff->ds == NULL && buff->idl == NULL && buff->sad != NULL)
    return 0;

  set_declaration_scope (buff);

  if (buff->ds != NULL && buff->idl == NULL)
    return create_symbol_one_for_ds (buff, syms);
  else if (buff->ds != NULL && buff->idl != NULL)
    return create_symbols_for_list (buff, syms);
  else
    return 0;                   /* BUG! */
}

static int
create_symbol_one_for_ds (struct declaration *buff, symbol_t *** syms)
{
  assert (buff != NULL);
  assert (syms != NULL);

  *syms = calloc (1, sizeof (symbol_t *));
  assert (*syms != NULL);

  (*syms)[0] = create_symbol_from_declaration_specifiers (buff->ds);
  if ((*syms)[0] == NULL)
    {
      free (*syms);
      return 0;
    }

  create_symbol_adjust_scope (buff, (*syms)[0]);
  return 1;
}

static void
create_symbol_adjust_scope (struct declaration *buff, symbol_t * sym)
{
  assert (buff != NULL);
  assert (sym != NULL);

  switch (buff->parent_kind)
    {
    case NODE_BLOCK_ITEM:
      {
        sym->scope_kind = NODE_COMPOUND_STATEMENT;
        struct block_item *aux1 = buff->parent;
        struct block_item_list *aux2 = aux1->parent;
        sym->scope = aux2->parent;
      }
      break;

    case NODE_ITERATION_STATEMENT:
      sym->scope_kind = NODE_ITERATION_STATEMENT;
      sym->scope = buff->parent;
      break;

    case NODE_EXTERNAL_DECLARATION:
      sym->scope_kind = NODE_TRANSLATION_UNIT;
      sym->scope = ((struct external_declaration *) (buff->parent))->parent;
      break;

    case NODE_DECLARATION_LIST:
      {
        sym->scope_kind = NODE_COMPOUND_STATEMENT;
        struct declaration_list *aux1 = buff->parent;
        struct function_definition *aux2 = aux1->parent;
        sym->scope = aux2->cs;
      }
      break;

    default:
      ;
    }
}

static int
create_symbols_for_list (struct declaration *buff, symbol_t *** syms)
{
  assert (buff != NULL);
  assert (syms != NULL);

  //int is_typedef = is_there_typedef (buff->ds);
  symbol_t **aux;
  int i = 0, n = create_symbols_for_init_declarator_list (buff->idl, &aux);

  /*
   * Achtung! A declaration may declare two things at once:
   * a type and a variable. For example:
   * struct mytag { ... } myvar;
   * and we must create one symbol for each.
   */

  symbol_t *extra = create_symbol_from_declaration_specifiers (buff->ds);
  if (extra != NULL)
    n++;
  *syms = calloc (n, sizeof (symbol_t *));
  assert (*syms != NULL);
  if (extra == NULL)
    for (int i = 0; i < n; i++)
      (*syms)[i] = aux[i];
  else
    for (int i = 0; i < n - 1; i++)
      (*syms)[i] = aux[i];
  if (extra != NULL)
    (*syms)[n - 1] = extra;
  free (aux);

  for (i = 0; i < n; i++)
    create_symbol_adjust_scope (buff, (*syms)[i]);

  return n;
}

void
set_declaration_scope (struct declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION);

  if (buff->scope != NULL && buff->scope_kind != NODE_UNDEFINED)
    return;

  switch (buff->parent_kind)
    {
    case NODE_BLOCK_ITEM:
      {
        /* 
         * that's easy because block items
         * belong to a compound statement.
         */
        struct block_item_list *bil =
          ((struct block_item *) buff->parent)->parent;
        buff->scope = bil->parent;
        buff->scope_kind = NODE_COMPOUND_STATEMENT;
      }
      break;

    case NODE_ITERATION_STATEMENT:
      /* note only for certain kinds of 'foor' loops */
      buff->scope = buff->parent;
      buff->scope_kind = NODE_ITERATION_STATEMENT;
      break;

    case NODE_EXTERNAL_DECLARATION:
      buff->scope = ((struct external_declaration *) buff->parent)->parent;
      buff->scope_kind = NODE_TRANSLATION_UNIT;
      break;

    case NODE_DECLARATION_LIST:
      {
        /*
         * The parent of a declaration-list
         * is a function definition, whose parent
         * is an external declaration.
         */
        struct function_definition *fd =
          ((struct declaration_list *) buff->parent)->parent;
        buff->scope = ((struct external_declaration *) fd->parent)->parent;
        buff->scope_kind = NODE_TRANSLATION_UNIT;
      }
      break;

    default:
      ;                         /* BUG! */
    }
}
