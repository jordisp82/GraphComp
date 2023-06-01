#ifndef DESIGNATION_H
#define DESIGNATION_H

/**
 * designation:
 *      designator-list '='
 * 
 * parents:
 *      initializer-list (1)(3)
 */

#include "node_kind_t.h"
#include "structs.h"

struct designation
{
  node_kind_t kind;
  struct designator_list *dl;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_designation_scope (struct designation *buff);

#endif
