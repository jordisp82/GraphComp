#ifndef INIT_DECLARATOR_LIST_H
#define INIT_DECLARATOR_LIST_H

/**
 * init-declarator-list:
 *      init-declarator         (1)
 *      init-declarator-list ',' init-declarator    (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct init_declarator_list
{
  node_kind_t kind;
  struct idl_node
  {
    struct init_declarator *id;
    struct idl_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif