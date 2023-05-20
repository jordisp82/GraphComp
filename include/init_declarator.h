#ifndef INIT_DECLARATOR_H
#define INIT_DECLARATOR_H

/**
 * init-declarator:
 *      declarator '=' initializer          (1)
 *      declarator          (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct init_declarator
{
  node_kind_t kind;
  struct declarator *dclr;
  struct initializer *itz;
  node_kind_t parent_kind;
  void *parent;
};

#endif
