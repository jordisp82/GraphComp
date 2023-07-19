#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <string.h>

#include "misra.h"
#include "misra_5_7.h"
#include "structs.h"
#include "node_kind_t.h"
#include "avl_tree.h"
#include "symtable.h"
#include "declarator.h"
#include "init_declarator.h"
#include "init_declarator_list.h"
#include "declaration.h"
#include "declaration_specifiers.h"
#include "type_specifier.h"
#include "struct_or_union_specifier.h"
#include "struct_or_union.h"
#include "enum_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void check_avl_5_7 (avl_node_t * tags, avl_node_t * ord);
static void check_sym_tbl_5_7 (struct symtable *p, struct symtable *s);
static symbol_t *check_sym_5_7 (symbol_t * sym, avl_node_t * tree);
static int is_exception (symbol_t * tag, symbol_t * ord);

void
check_misra_5_7 (struct symtable *sym_table)
{
  assert (sym_table != NULL);

  /*
   * It's quite similar to rule 5.6, but this
   * time we already know which symbols are
   * tags.
   * The only fucking problem is that of the
   * exception.
   */

  if (sym_table->tags != NULL && sym_table->ord != NULL)
    check_avl_5_7 (sym_table->tags, sym_table->ord);

  for (int i = 0; i < sym_table->n_children; i++)
    check_sym_tbl_5_7 (sym_table, sym_table->children[i]);

  for (int i = 0; i < sym_table->n_children; i++)
    check_misra_5_7 (sym_table->children[i]);
}

static void
check_avl_5_7 (avl_node_t * tags, avl_node_t * ord)
{
  assert (tags != NULL);
  assert (ord != NULL);

  symbol_t *aux = check_sym_5_7 (tags->value, ord);

  if (aux != NULL)
    tags->value->misra_5_7 = aux;
  if (tags->left != NULL)
    check_avl_5_7 (tags->left, ord);
  if (tags->right != NULL)
    check_avl_5_7 (tags->right, ord);
}

static void
check_sym_tbl_5_7 (struct symtable *p, struct symtable *s)
{
  assert (p != NULL);
  assert (s != NULL);

  if (p->tags != NULL && s->ord != NULL)
    check_avl_5_7 (p->tags, s->ord);
  if (p->ord != NULL && s->tags != NULL)
    check_avl_5_7 (s->tags, p->ord);

  for (int i = 0; i < s->n_children; i++)
    check_sym_tbl_5_7 (p, s->children[i]);
}

static symbol_t *
check_sym_5_7 (symbol_t * sym, avl_node_t * tree)
{
  assert (sym != NULL);
  assert (tree != NULL);

  int n = strcmp (sym->name, tree->value->name);
  if (n < 0 && tree->left != NULL)
    return check_sym_5_7 (sym, tree->left);
  else if (n > 0 && tree->right != NULL)
    return check_sym_5_7 (sym, tree->right);
  else if (n == 0)
    if (is_exception (sym, tree->value) == 0)
      return sym;

  return NULL;
}

static int
is_exception (symbol_t * tag, symbol_t * ord)
{
  assert (tag != NULL);
  assert (ord != NULL);
  assert (tag->name != NULL);

  /*
   * First, ord shall be a typedef.
   * Second, it shall be the typedef
   * for that tag.
   */

  if (is_typedef (ord) == 0)
    return 0;

  struct declarator *d = ord->node;
  struct init_declarator_list *idl =
    ((struct init_declarator *) (d->parent))->parent;
  struct declaration_specifiers *buff =
    ((struct declaration *) (idl->parent))->ds;

  /*
   * Now, inside the declaration specifiers,
   * there must be a type specifier that must
   * be a struct specifier with the same tag.
   * NOTE since C puts *all tags* in the same namespace,
   * we don't need to check that both the tag and the
   * typedef are for the same kind of thing, either a struct,
   * a union or an enum.
   */

  for (struct ds_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    if (ptr->ds_kind == NODE_TYPE_SPECIFIER)
      {
        if (ptr->ts->ts_kind == TS_STRUCT_UNION && ptr->ts->sus->tag != NULL
            && strcmp (tag->name, ptr->ts->sus->tag) == 0)
          return 1;
        else if (ptr->ts->ts_kind == TS_ENUM && ptr->ts->es->tag != NULL
                 && strcmp (tag->name, ptr->ts->es->tag) == 0)
          return 1;
      }

  return 0;
}
