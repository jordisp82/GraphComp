#ifndef SPECIFIER_QUALIFIER_LIST_H
#define SPECIFIER_QUALIFIER_LIST_H

/**
 * specifier-qualifier-list:
 *      type-specifier specifier-qualifier-list         (1)
 *      type-specifier          (2)
 *      type-qualifier specifier-qualifier-list         (3)
 *      type-qualifier          (4)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  SQ_TYPE_SPEC,
  SQ_TYPE_QUAL
} sq_kind_t;

struct specifier_qualifier_list
{
  node_kind_t kind;
  struct sql_node
  {
    sq_kind_t sq_kind;
    union
    {
      struct type_specifier *ts;
      struct type_qualifier *tq;
    };
    struct sql_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif
