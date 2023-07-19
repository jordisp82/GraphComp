#ifndef TRANSLATION_UNIT_H
#define TRANSLATION_UNIT_H

/**
 * translation-unit:
 *      external-declaration        (1)
 *      translation-unit external-declaration       (2)
 * 
 * Rule (1) is straightforward. Rule (2) is a pain in the ass.
 * It means that, if a file has, let's say, 50 external declarations,
 * there will be 50 external declaration nodes and about 50 nodes
 * of translation unit. We don't want this. We want one node of
 * translation unit and 50 nodes of external declarations.
 */

#include "node_kind_t.h"
#include "structs.h"
//#include "avl_tree.h"
#include "symtable.h"

struct translation_unit
{
  node_kind_t kind;
  struct tu_node
  {
    struct external_declaration *ed;
    struct tu_node *next;
  } *first, *last;
  struct symtable *sym_table;
  void (*create_symtable) (struct translation_unit * buff);
  void (*create_symbol) (struct translation_unit * buff);
};

#endif
