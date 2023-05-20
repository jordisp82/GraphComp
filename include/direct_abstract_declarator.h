#ifndef DIRECT_ABSTRACT_DECLARATOR_H
#define DIRECT_ABSTRACT_DECLARATOR_H

/**
 */

#include "node_kind_t.h"
#include "structs.h"

struct direct_abstract_declarator
{
  node_kind_t kind;
  node_kind_t parent_kind;
  void *parent;
};

#endif
