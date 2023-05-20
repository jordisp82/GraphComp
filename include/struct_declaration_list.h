#ifndef STRUCT_DECLARATION_LIST_H
#define STRUCT_DECLARATION_LIST_H

/**
 * struct-declaration-list:
 *      struct-declaration              (1)
 *      struct-declaration-list struct-declaration      (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct struct_declaration_list
{
  node_kind_t kind;
  struct sdl_node
  {
    struct struct_declaration *sd;
    struct sdl_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif