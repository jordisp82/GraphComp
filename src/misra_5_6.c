#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <string.h>

#include "misra.h"
#include "misra_5_6.h"
#include "structs.h"
#include "node_kind_t.h"
#include "avl_tree.h"
#include "symtable.h"
#include "declarator.h"
#include "declaration.h"
#include "declaration_specifiers.h"
#include "storage_class_specifier.h"
#include "init_declarator.h"
#include "init_declarator_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void check_avl_5_6 (avl_node_t * first, avl_node_t * second);
static void check_sym_tbl_5_6 (struct symtable *p, struct symtable *s);
static symbol_t *check_sym_5_6 (symbol_t * sym, avl_node_t * tree);

void
check_misra_5_6 (struct symtable *sym_table)
{
  assert (sym_table != NULL);

  /*
   * For each of our AVLs, we're going to check it
   * against the AVLs of our children, grandchildren
   * and so on. And also our AVLs against themselves.
   */

  if (sym_table->ord != NULL && sym_table->tags != NULL)
    check_avl_5_6 (sym_table->ord, sym_table->tags);

  for (int i = 0; i < sym_table->n_children; i++)
    check_sym_tbl_5_6 (sym_table, sym_table->children[i]);

  for (int i = 0; i < sym_table->n_children; i++)
    check_misra_5_6 (sym_table->children[i]);
}

static void
check_avl_5_6 (avl_node_t * first, avl_node_t * second)
{
  assert (first != NULL);
  assert (second != NULL);

  symbol_t *aux = check_sym_5_6 (first->value, second);

  if (aux != NULL)
    first->value->misra_5_6 = aux;
  if (first->left != NULL)
    check_avl_5_6 (first->left, second);
  if (first->right != NULL)
    check_avl_5_6 (first->right, second);
}

static void
check_sym_tbl_5_6 (struct symtable *p, struct symtable *s)
{
  assert (p != NULL);
  assert (s != NULL);

  if (p->ord != NULL && s->ord != NULL)
    check_avl_5_6 (p->ord, s->ord);
  if (p->ord != NULL && s->tags != NULL)
    check_avl_5_6 (p->ord, s->tags);
  if (p->tags != NULL && s->ord != NULL)
    check_avl_5_6 (p->tags, s->ord);
  if (p->tags != NULL && s->tags != NULL)
    check_avl_5_6 (p->tags, s->tags);

  for (int i = 0; i < s->n_children; i++)
    check_sym_tbl_5_6 (p, s->children[i]);
}

static symbol_t *
check_sym_5_6 (symbol_t * sym, avl_node_t * tree)
{
  assert (sym != NULL);
  assert (tree != NULL);

  /*
   * The name must be identical, but also
   * one of the symbols must be a typedef name.
   */

  int n = strcmp (sym->name, tree->value->name);
  if (n < 0 && tree->left != NULL)
    return check_sym_5_6 (sym, tree->left);
  else if (n > 0 && tree->right != NULL)
    return check_sym_5_6 (sym, tree->right);
  else if (n == 0)
    if (is_typedef (sym) == 1 || is_typedef (tree->value) == 1)
      return tree->value;

  return NULL;
}

int
is_typedef (symbol_t * sym)
{
  assert (sym != NULL);

  if (sym->node_kind != NODE_DECLARATOR)
    return 0;

  /*
   * A typedef can only be a declaration.
   * The parent of a declarator can be several
   * things; we can discard function-definition,
   * parameter-declaration, and struct-declarator.
   * We know that it won't be a direct-declarator,
   * see direct_declarator.c
   */

  struct declarator *d = sym->node;
  switch (d->parent_kind)
    {
    case NODE_FUNCTION_DEFINITION:
    case NODE_STRUCT_DECLARATION:
    case NODE_PARAMETER_DECLARATION:
      return 0;

    case NODE_INIT_DECLARATOR:
      break;

    default:
      return -1;                /* BUG! */
    }

  struct init_declarator_list *idl =
    ((struct init_declarator *) (d->parent))->parent;
  struct declaration *buff = idl->parent;

  for (struct ds_node * ptr = buff->ds->first; ptr != NULL; ptr = ptr->next)
    if (ptr->ds_kind == NODE_STORAGE_CLASS_SPECIFIER)
      if (ptr->stg->kind == STG_TYPEDEF)
        return 1;

  return 0;
}

#if 0
static int
is_typedef (struct declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION);

  for (struct ds_node * ptr = buff->ds->first; ptr != NULL; ptr = ptr->next)
    if (ptr->ds_kind == NODE_STORAGE_CLASS_SPECIFIER)
      if (ptr->stg->kind == STG_TYPEDEF)
        return 1;

  return 0;
}
#endif

#if 0
static void avl_5_3 (avl_node_t * inner, avl_node_t * outer);

void
check_misra_5_3 (struct symtable *sym_table)
{
  assert (sym_table != NULL);

  /*
   * The rule is violated not only when
   * the current symbol table hides
   * someting of its parend, but also
   * when it hides something of its
   * grand(grand)parents.
   */

  for (struct symtable * parent = sym_table->parent; parent != NULL;
       parent = parent->parent)
    {
      avl_5_3 (sym_table->ord, parent->ord);
      avl_5_3 (sym_table->tags, parent->tags);
    }

  /* and now the children, if any */

  for (int i = 0; i < sym_table->n_children; i++)
    check_misra_5_3 (sym_table->children[i]);
}

static void
avl_5_3 (avl_node_t * inner, avl_node_t * outer)
{
  assert (inner != NULL);
  assert (outer != NULL);

  if (strcmp (inner->value->name, outer->value->name) == 0)
    inner->value->misra_5_3 = outer->value;

  if (inner->left != NULL && outer->left != NULL)
    avl_5_3 (inner->left, outer->left);
  if (inner->right != NULL && outer->right != NULL)
    avl_5_3 (inner->right, outer->right);
}
#endif
