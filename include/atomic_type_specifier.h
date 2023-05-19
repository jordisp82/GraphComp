#ifndef ATOMIC_TYPE_SPECIFIER_H
#define ATOMIC_TYPE_SPECIFIER_H

/**
 * atomic-type-specifier:
 *      ATOMIC '(' type-name ')'
 */

typedef enum
{
  NODE_ATOMIC_TYPE_SPECIFIER
} node_kind_t;

struct type_name;

struct atomic_type_specifier
{
  node_kind_t kind;
  struct type_name *tn;
  node_kind_t parent_kind;
  void *parent;
};

#endif
