#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symtable.h"
#include "ast.h"

static void sym_extern_decl (ast_node_t * ast, sym_node_t * sym);
static void sym_transl_unit (ast_node_t * ast, sym_node_t * sym);
static void sym_func_def (ast_node_t * ast, sym_node_t * sym);
static void sym_decl (ast_node_t * ast, sym_node_t * sym);
static void sym_comp_stmt0 (ast_node_t * ast, sym_node_t * sym);
static void sym_func_declr (ast_node_t * ast, sym_node_t * sym);
static void sym_func_dir_declr (ast_node_t * ast, sym_node_t * sym);
static void sym_par_type_list (ast_node_t * ast, sym_node_t * sym);
static void sym_par_list (ast_node_t * ast, sym_node_t * sym);
static void sym_par_decl (ast_node_t * ast, sym_node_t * sym);
static void sym_declarator (ast_node_t * ast, sym_node_t * sym);
static void sym_dir_declarator (ast_node_t * ast, sym_node_t * sym);
static void sym_init_declr_list (ast_node_t * ast, sym_node_t * sym);
static void sym_init_declr (ast_node_t * ast, sym_node_t * sym);
static void sym_block_item_list (ast_node_t * ast, sym_node_t * sym);
static void sym_block_item (ast_node_t * ast, sym_node_t * sym);
static void sym_stmt (ast_node_t * ast, sym_node_t * sym);
static void sym_comp_stmt1 (ast_node_t * ast, sym_node_t * sym);
static void sym_selection_stmt (ast_node_t * ast, sym_node_t * sym);
static void sym_iteration_stmt (ast_node_t * ast, sym_node_t * sym);
static void add_symbol (ast_node_t * ast, sym_node_t * sym);
static sym_node_t *new_sym_scope (ast_node_t * ast, sym_node_t * sym);
static void debug_print_symtable (sym_node_t * sym) __attribute__((unused));

sym_node_t *
create_symtable (ast_node_t * tu)
{
  assert (tu != NULL);
  assert (IS_TRANSLATION_UNIT (tu->func_ptr));

  sym_node_t *sym_table = calloc (1, sizeof (sym_node_t));
  assert (sym_table != NULL);
  sym_table->list = calloc (1, sizeof (symbol_t));
  assert (sym_table->list != NULL);
  sym_table->scope = tu;

  for (int i = 0; i < tu->n_children; i++)
    if (IS_EXTERNAL_DECLARATION (tu->children[i]->func_ptr))
      sym_extern_decl (tu->children[i], sym_table);
    else if (IS_TRANSLATION_UNIT (tu->children[i]->func_ptr))
      sym_transl_unit (tu->children[i], sym_table);

  debug_print_symtable (sym_table);
  return sym_table;
}

static void
sym_extern_decl (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  if (IS_FUNCTION_DEFINITION (ast->children[0]->func_ptr))
    sym_func_def (ast->children[0], sym);
  else if (IS_DECLARATION (ast->children[0]->func_ptr))
    sym_decl (ast->children[0], sym);
}

static void
sym_transl_unit (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  for (int i = 0; i < ast->n_children; i++)
    if (IS_EXTERNAL_DECLARATION (ast->children[i]->func_ptr))
      sym_extern_decl (ast->children[i], sym);
    else if (IS_TRANSLATION_UNIT (ast->children[i]->func_ptr))
      sym_transl_unit (ast->children[i], sym);
}

static void
sym_func_def (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  /* we choose not to support pre-ANSI C function definitions */
  if (ast->func_ptr == function_definition_1)
    return;

  assert (IS_DECLARATION_SPECS (ast->children[0]->func_ptr));
  assert (IS_DECLARATOR (ast->children[1]->func_ptr));
  assert (IS_COMPOUND_STATEMENT (ast->children[2]->func_ptr));

  sym_node_t *current = new_sym_scope (ast->children[2], sym);

  sym_func_declr (ast->children[1], current);
  sym_comp_stmt0 (ast->children[2], current);
}

static void
sym_decl (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  /*
   * We are interested in the declarators,
   * which are the only terminals that will
   * give us names. But the declaration
   * specifiers have to be looked at because
   * typedef could be there...
   */

  if (IS_DECLARATION_SPECS (ast->children[0]->func_ptr))
    if (look_for_typedef (ast->children[0]) == 1)
      return;

  for (int i = 0; i < ast->n_children; i++)
    if (IS_INIT_DECLARATOR_LIST (ast->children[i]->func_ptr))
      sym_init_declr_list (ast->children[i], sym);
}

static void
sym_comp_stmt0 (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  /* the new scope has already been created */

  /*
   * It may have just a pair of braces, or
   * a pair of braces and block list inside.
   */

  if (ast->n_children == 1)
    sym_block_item_list (ast->children[0], sym);
}

static void
sym_func_declr (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  /* it only has pointers and direct declarators */

  for (int i = 0; i < ast->n_children; i++)
    if (IS_DIRECT_DECLARATOR (ast->children[i]->func_ptr))
      sym_func_dir_declr (ast->children[i], sym);
}

static void
sym_func_dir_declr (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  if (ast->n_children == 0 && ast->token == IDENTIFIER)
    add_symbol (ast, sym->parent);
  else
    for (int i = 0; i < ast->n_children; i++)
      if (IS_DECLARATOR (ast->children[i]->func_ptr))
        sym_func_declr (ast->children[i], sym);
      else if (IS_DIRECT_DECLARATOR (ast->children[i]->func_ptr))
        sym_func_dir_declr (ast->children[i], sym);
      else if (IS_PARAMETER_TYPE_LIST (ast->children[i]->func_ptr))
        sym_par_type_list (ast->children[i], sym);
}

static void
sym_par_type_list (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);
  assert (IS_PARAMETER_LIST (ast->children[0]->func_ptr));

  sym_par_list (ast->children[0], sym);
}

static void
sym_par_list (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  for (int i = 0; i < ast->n_children; i++)
    if (IS_PARAMETER_LIST (ast->children[i]->func_ptr))
      sym_par_list (ast->children[i], sym);
    else if (IS_PARAMETER_DECLARATION (ast->children[i]->func_ptr))
      sym_par_decl (ast->children[i], sym);
}

static void
sym_par_decl (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  /*
   * We don't need the declaration specifiers.
   * The difference between a declarator and an
   * abstract declarator is that the second one
   * does not include an identifier, so we're
   * going to ignore abstract things
   */

  for (int i = 0; i < ast->n_children; i++)
    if (IS_DECLARATOR (ast->children[i]->func_ptr))
      sym_declarator (ast->children[i], sym);
}

static void
sym_declarator (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  /* it only has pointers and direct declarators */

  for (int i = 0; i < ast->n_children; i++)
    if (IS_DIRECT_DECLARATOR (ast->children[i]->func_ptr))
      sym_dir_declarator (ast->children[i], sym);
}

static void
sym_dir_declarator (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  if (ast->n_children == 0 && ast->token == IDENTIFIER)
    add_symbol (ast, sym);
  else
    for (int i = 0; i < ast->n_children; i++)
      if (IS_DECLARATOR (ast->children[i]->func_ptr))
        sym_declarator (ast->children[i], sym);
      else if (IS_DIRECT_DECLARATOR (ast->children[i]->func_ptr))
        sym_dir_declarator (ast->children[i], sym);
}

static void
sym_init_declr_list (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  for (int i = 0; i < ast->n_children; i++)
    if (IS_INIT_DECLARATOR (ast->children[i]->func_ptr))
      sym_init_declr (ast->children[i], sym);
}

static void
sym_init_declr (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);
  assert (IS_DECLARATOR (ast->children[0]->func_ptr));

  sym_declarator (ast->children[0], sym);
}

static void
sym_block_item_list (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  for (int i = 0; i < ast->n_children; i++)
    if (IS_BLOCK_ITEM_LIST (ast->children[i]->func_ptr))
      sym_block_item_list (ast->children[i], sym);
    else if (IS_BLOCK_ITEM (ast->children[i]->func_ptr))
      sym_block_item (ast->children[i], sym);
}

static void
sym_block_item (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  if (IS_DECLARATION (ast->children[0]->func_ptr))
    sym_decl (ast->children[0], sym);
  else if (IS_STATEMENT (ast->children[0]->func_ptr))
    sym_stmt (ast->children[0], sym);
}

static void
sym_stmt (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  /* we focus only in certain kind of statements */

  if (IS_COMPOUND_STATEMENT (ast->children[0]->func_ptr))
    sym_comp_stmt1 (ast->children[0], sym);
  else if (IS_SELECTION_STATEMENT (ast->children[0]->func_ptr))
    sym_selection_stmt (ast->children[0], sym);
  else if (IS_ITERATION_STATEMENT (ast->children[0]->func_ptr))
    sym_iteration_stmt (ast->children[0], sym);
}

static void
sym_comp_stmt1 (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  sym_node_t *current = new_sym_scope (ast, sym);

  sym_comp_stmt0 (ast, current);
}

static void
sym_selection_stmt (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  for (int i = 0; i < ast->n_children; i++)
    if (IS_STATEMENT (ast->children[i]->func_ptr))
      sym_stmt (ast->children[i], sym);
}

static void
sym_iteration_stmt (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  /* beware with for loops */

  if (ast->func_ptr == iteration_statement_1
      || ast->func_ptr == iteration_statement_2
      || ast->func_ptr == iteration_statement_3
      || ast->func_ptr == iteration_statement_4)
    {
      for (int i = 0; i < ast->n_children; i++)
        if (IS_STATEMENT (ast->children[i]->func_ptr))
          sym_stmt (ast->children[i], sym);
    }
  else if (ast->func_ptr == iteration_statement_5
           || ast->func_ptr == iteration_statement_6)
    {
      sym_node_t *current = new_sym_scope (ast, sym);
      for (int i = 0; i < ast->n_children; i++)
        if (IS_DECLARATION (ast->children[i]->func_ptr))
          sym_decl (ast->children[i], current);
        else if (IS_STATEMENT (ast->children[i]->func_ptr))
          sym_stmt (ast->children[i], current);
    }
}

static void
add_symbol (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  symbol_t *new_sym = calloc (1, sizeof (symbol_t));
  assert (new_sym != NULL);

  new_sym->name = strdup (ast->data);
  assert (new_sym->name != NULL);
  new_sym->decl = ast;
  new_sym->next = sym->list->next;
  sym->list->next = new_sym;

  printf ("[%s] Added symbol '%s'\n", __func__, new_sym->name);
}

static sym_node_t *
new_sym_scope (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  sym->n_children++;
  sym->children =
    realloc (sym->children, sym->n_children * sizeof (sym_node_t *));
  assert (sym->children != NULL);
  sym->children[sym->n_children - 1] = calloc (1, sizeof (sym_node_t));
  sym_node_t *current = sym->children[sym->n_children - 1];
  assert (current != NULL);
  current->parent = sym;
  current->list = calloc (1, sizeof (symbol_t));
  assert (current->list != NULL);
  current->scope = ast;

  return current;
}

static void
debug_print_symtable (sym_node_t * sym)
{
  printf ("\n{\n");
  for (symbol_t * ptr = sym->list->next; ptr != NULL; ptr = ptr->next)
    printf (" %s", ptr->name);
  for (int i = 0; i < sym->n_children; i++)
    debug_print_symtable (sym->children[i]);
  printf ("\n}\n");
}
