#ifndef STRUCT_OR_UNION_H
#define STRUCT_OR_UNION_H

/**
 * struct-or-union:
 *      STRUCT          (1)
 *      UNION           (2)
 * 
 * parents:
 *      struct-or-union-specifier (1)(2)(3)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  SU_STRUCT,
  SU_UNION
} su_kind_t;

struct struct_or_union
{
  node_kind_t kind;
  su_kind_t value;
  node_kind_t parent_kind;
  void *parent;
};

#endif
