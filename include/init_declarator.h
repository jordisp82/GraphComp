#ifndef INIT_DECLARATOR_H
#define INIT_DECLARATOR_H

/**
 * init-declarator:
 *      declarator '=' initializer          (1)
 *      declarator          (2)
 * 
 * parents:
 *      init-declarator-list (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct init_declarator
{
  node_kind_t kind;
  struct declarator *dclr;
  struct initializer *itz;
  void (*dot_create) (void *node, void *f);
  /* NOTE start of experimental code */
  int (*sem_analysis) (void *node);
  /* NOTE end of experimental code */
  node_kind_t parent_kind;
  void *parent;
};

#endif
