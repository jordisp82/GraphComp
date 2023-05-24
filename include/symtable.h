#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "symbol.h"
#include "avl_tree.h"

/*
 * struct and union fields won't be stored into
 * the symbol table; they belong to their type
 * definition.
 */

struct symtable
{
  avl_node *ns_labels;
  avl_node *ns_tags;
  avl_node *ns_ordinary;
};

#endif
