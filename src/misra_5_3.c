#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <string.h>

#include "misra_5_3.h"
#include "structs.h"
#include "node_kind_t.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void check_avl_5_3 (avl_node_t * inner, avl_node_t * outer);
static symbol_t *check_sym_5_3 (symbol_t * sym, avl_node_t * tree);

void
check_misra_5_3 (struct symtable *sym_table)
{
  assert (sym_table != NULL);

  /*
   * The rule is violated not only when
   * the current symbol table hides
   * someting of its parent, but also
   * when it hides something of its
   * grand(grand)parents.
   */

  for (struct symtable * parent = sym_table->parent; parent != NULL;
       parent = parent->parent)
    {
      check_avl_5_3 (sym_table->ord, parent->ord);
      check_avl_5_3 (sym_table->tags, parent->tags);
    }

  /* and now the children, if any */

  for (int i = 0; i < sym_table->n_children; i++)
    check_misra_5_3 (sym_table->children[i]);
}

static void
check_avl_5_3 (avl_node_t * inner, avl_node_t * outer)
{
  assert (inner != NULL);
  assert (outer != NULL);

  symbol_t *aux = check_sym_5_3 (inner->value, outer);

  if (aux != NULL)
    inner->value->misra_5_3 = aux;
  if (inner->left != NULL)
    check_avl_5_3 (inner->left, outer);
  if (inner->right != NULL)
    check_avl_5_3 (inner->right, outer);
}

static symbol_t *
check_sym_5_3 (symbol_t * sym, avl_node_t * tree)
{
  assert (sym != NULL);
  assert (tree != NULL);

  int n = strcmp (sym->name, tree->value->name);
  if (n == 0)
    return tree->value;
  else if (n < 0 && tree->left != NULL)
    return check_sym_5_3 (sym, tree->left);
  else if (n > 0 && tree->right != NULL)
    return check_sym_5_3 (sym, tree->right);

  return NULL;
}
