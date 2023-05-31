#ifndef ATOMIC_TYPE_SPECIFIER_H
#define ATOMIC_TYPE_SPECIFIER_H

/**
 * atomic-type-specifier:
 *      ATOMIC '(' type-name ')'
 * 
 * parents:
 *      type-specifier (13)
 */

#include "node_kind_t.h"
#include "structs.h"

struct atomic_type_specifier
{
  node_kind_t kind;
  struct type_name *tn;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_atomic_specifier_scope (struct atomic_type_specifier *buff);

#endif
