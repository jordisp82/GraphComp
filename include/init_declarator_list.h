#ifndef INIT_DECLARATOR_LIST_H
#define INIT_DECLARATOR_LIST_H

/**
 * init-declarator-list:
 *      init-declarator         (1)
 *      init-declarator-list ',' init-declarator    (2)
 * 
 * parents:
 *      declaration (2)
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
  void (*dot_create) (void *node, void *f);
  /* NOTE start of experimental code */
  int (*sem_analysis) (void *node);
  /* NOTE end of experimental code */
  node_kind_t parent_kind;
  void *parent;
};

#endif
