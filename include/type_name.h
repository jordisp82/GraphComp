#ifndef TYPE_NAME_H
#define TYPE_NAME_H

/**
 * type-name:
 *      specifier-qualifier-list abstract-declarator        (1)
 *      specifier-qualifier-list            (2)
 */

#include "node_kind_t.h"
#include "structs.h"

struct type_name
{
  node_kind_t kind;
  struct specifier_qualifier_list *sql;
  struct abstract_declarator *adlr;
  node_kind_t parent_kind;
  void *parent;
};

#endif
