#ifndef ABSTRACT_DECLARATOR_H
#define ABSTRACT_DECLARATOR_H

/**
 * abstract-declarator:
 *      pointer direct-abstract-declarator          (1)
 *      pointer                 (2)
 *      direct-abstract-declarator                  (3)
 */

#include "node_kind_t.h"
#include "structs.h"

struct abstract_declarator
{
  node_kind_t kind;
  struct pointer *ptr;
  struct direct_abstract_declarator *dad;
  node_kind_t parent_kind;
  void *parent;
};

#endif
