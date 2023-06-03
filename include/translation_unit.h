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
#include "avl_tree.h"

struct translation_unit
{
  node_kind_t kind;
  struct tu_node
  {
    struct external_declaration *ed;
    struct tu_node *next;
  } *first, *last;
  avl_node_t *ordinary;
  avl_node_t *tags;
};

void create_symbol_table_file (struct translation_unit *buff);
symbol_t *look_for_id_in_tu (struct translation_unit *buff, const char *name);
void fill_in_symtable_tu (struct translation_unit *buff);

#endif
