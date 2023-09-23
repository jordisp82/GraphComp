#ifndef TYPE_QUALIFIER_LIST_H
#define TYPE_QUALIFIER_LIST_H

/**
 * type-qualifier-list:
 *      type-qualifier          (1)
 *      type-qualifier-list type-qualifier      (2)
 * 
 * parents:
 *      direct-declarator (5)(7)(8)(9)(10)
 *      pointer (1)(2)
 *      direct-abstract-declarator (4)(6)(7)(8)(12)(14)(15)(16)
 */

#include "node_kind_t.h"
#include "structs.h"

struct type_qualifier_list
{
  node_kind_t kind;
  struct tql_node
  {
    struct type_qualifier *tq;
    struct tql_node *next;
  } *first, *last;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
