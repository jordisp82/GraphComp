#ifndef DESIGNATION_H
#define DESIGNATION_H

/**
 * designation:
 *      designator-list '='
 * 
 * Trivial.
 */

#include "node_kind_t.h"
#include "structs.h"

struct designation
{
  node_kind_t kind;
  struct designator_list *dl;
  node_kind_t parent_kind;
  void *parent;
};

#endif