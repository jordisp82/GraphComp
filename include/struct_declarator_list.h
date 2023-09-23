#ifndef STRUCT_DECLARATOR_LIST_H
#define STRUCT_DECLARATOR_LIST_H

/**
 * struct-declarator-list:
 *      struct-declarator           (1)
 *      struct-declarator-list ',' struct-declarator        (2)
 * 
 * parents:
 *      struct-declaration (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct struct_declarator_list
{
  node_kind_t kind;
  struct sdl_node
  {
    struct struct_declarator *sd;
    struct sdl_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif
