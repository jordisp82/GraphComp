#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "avl_tree.h"
#include "node_kind_t.h"

struct symtable
{
  struct symtable *parent;      /* NULL for a translation unit */
  void *node;                   /* node that creates this symbol table */
  node_kind_t node_kind;
  int n_children;               /* how many descendant symbol tables */
  struct symtable **children;
  /* labels are ignored because gotos are forbidden by MISRA */
  avl_node_t *tags;             /* one for all tags */
  avl_node_t *ord;              /* including enum constants but not struct and union fields */
};

#endif
