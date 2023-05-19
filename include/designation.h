#ifndef DESIGNATION_H
#define DESIGNATION_H

/**
 * designation:
 *      designator-list '='
 * 
 * Trivial.
 */

typedef enum
{
  NODE_DESIGNATION
} node_kind_t;

struct designator_list;

struct designation
{
  node_kind_t kind;
  struct designator_list *dl;
  node_kind_t parent_kind;
  void *parent;
};

#endif
