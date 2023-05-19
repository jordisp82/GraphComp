#ifndef TYPE_QUALIFIER_LIST_H
#define TYPE_QUALIFIER_LIST_H

/**
 * type-qualifier-list:
 *      type-qualifier          (1)
 *      type-qualifier-list type-qualifier      (2)
 * 
 * This is a list.
 */

typedef enum
{
  NODE_TYPE_QUALIFIER_LIST
} node_kind_t;

struct type_qualifier;

struct type_qualifier_list
{
  node_kind_t kind;
  struct tql_node
  {
    struct type_qualifier *tq;
    struct tql_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif
