#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "grammar.tab.h"

ast_id_t ghost1 = { NULL, NULL };
ast_id_t ghost2 = { NULL, NULL };
ast_scope_t root_scope = { &ghost1, &ghost2, NULL };
ast_scope_t *current_scope = &root_scope;

int
sym_type (const char *str)
{
  assert (str != NULL);

  ast_id_t *ptr = NULL;

  /* let's start by the current scope */
  for (ptr = current_scope->typedefs->next; ptr != NULL; ptr = ptr->next)
    if (strcmp (str, ptr->str) == 0)
      return TYPEDEF_NAME;
  for (ptr = current_scope->enumconsts->next; ptr != NULL; ptr = ptr->next)
    if (strcmp (str, ptr->str) == 0)
      return ENUMERATION_CONSTANT;

  /* let's look at the higher scopes */
  ast_scope_t *scope = current_scope->parent;
  while (scope != NULL)
    {
      for (ptr = scope->typedefs->next; ptr != NULL; ptr = ptr->next)
        if (strcmp (str, ptr->str) == 0)
          return TYPEDEF_NAME;
      for (ptr = scope->enumconsts->next; ptr != NULL; ptr = ptr->next)
        if (strcmp (str, ptr->str) == 0)
          return ENUMERATION_CONSTANT;
      scope = scope->parent;
    }

  return IDENTIFIER;
}

void
push_scope (void)
{
  ast_scope_t *ptr = calloc (1, sizeof (ast_scope_t));
  assert (ptr != NULL);
  ptr->enumconsts = calloc (1, sizeof (ast_id_t));
  assert (ptr->enumconsts != NULL);
  ptr->typedefs = calloc (1, sizeof (ast_id_t));
  assert (ptr->typedefs != NULL);
  ptr->parent = current_scope;
  current_scope = ptr;
}

void
pull_scope (void)
{
  ast_scope_t *ptr = current_scope;
  current_scope = ptr->parent;
  ast_id_t *tmp;
  do
    {
      tmp = ptr->enumconsts;
      ptr->enumconsts = tmp->next;
      free ((void *) tmp->str);
      free (tmp);
    }
  while (ptr->enumconsts != NULL);
  do
    {
      tmp = ptr->typedefs;
      ptr->typedefs = tmp->next;
      free ((void *) tmp->str);
      free (tmp);
    }
  while (ptr->typedefs != NULL);
  free (ptr);
}

#if 0
static void
scope_add_enumeration_constant (const char *str)
{
  assert (str != NULL);

  ast_id_t *id = calloc (1, sizeof (ast_id_t));
  assert (id != NULL);
  id->str = strdup (str);
  assert (id->str != NULL);
  id->next = current_scope->enumconsts->next;
  current_scope->enumconsts->next = id;
#if 0
  printf ("[%s] added '%s'\n", __func__, str);
#endif
}

static void
scope_add_typedef (const char *str)
{
  assert (str != NULL);

  ast_id_t *id = calloc (1, sizeof (ast_id_t));
  assert (id != NULL);
  id->str = strdup (str);
  assert (id->str != NULL);
  id->next = current_scope->typedefs->next;
  current_scope->typedefs->next = id;
#if 0
  printf ("[%s] added '%s'\n", __func__, str);
#endif
}

int
look_for_typedef (ast_node_t * node)
{
  assert (node != NULL);

  if (IS_STORAGE_CLASS_SPEC (node->func_ptr) && node->token == TYPEDEF)
    return 1;

  if (node->n_children == 0)
    return 0;

  for (int i = 0; i < node->n_children; i++)
    if (look_for_typedef (node->children[i]) == 1)
      return 1;

  return 0;
}

static void
register_id_as_typedef (ast_node_t * node)
{
  assert (node != NULL);

  if (node->func_ptr == direct_declarator_1 && node->token == IDENTIFIER)
    scope_add_typedef (node->data);
  else
    for (int i = 0; i < node->n_children; i++)
      register_id_as_typedef (node->children[i]);
}
#endif
