#include <assert.h>
#include <stdlib.h>

#include "symtable.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

symtable_t *
symtable_create (void)
{
  symtable_t *table = calloc (1, sizeof (symtable_t));
  assert (table != NULL);

  return table;
}

void
symtable_add_label (symtable_t * table, symbol_t * sym)
{
  assert (table != NULL);
  assert (sym != NULL);
  assert (sym->name != NULL);

  if (table->ns_labels == NULL)
    table->ns_labels = avl_create (sym);
  else if (avl_add (table->ns_labels, sym) < 0)
    ;                           /* TODO already declared! */
  assert (table->ns_labels != NULL);
}

void
symtable_add_tag (symtable_t * table, symbol_t * sym)
{
  assert (table != NULL);
  assert (sym != NULL);
  assert (sym->name != NULL);

  if (table->ns_tags == NULL)
    table->ns_tags = avl_create (sym);
  else if (avl_add (table->ns_tags, sym) < 0)
    ;                           /* TODO already declared! */
  assert (table->ns_tags != NULL);
}

void
symtable_add_other (symtable_t * table, symbol_t * sym)
{
  assert (table != NULL);
  assert (sym != NULL);
  assert (sym->name != NULL);

  if (table->ns_ordinary == NULL)
    table->ns_ordinary = avl_create (sym);
  else if (avl_add (table->ns_ordinary, sym) < 0)
    ;                           /* TODO already declared! */
  assert (table->ns_ordinary != NULL);
}
