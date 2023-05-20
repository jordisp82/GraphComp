#ifndef DESIGNATOR_H
#define DESIGNATOR_H

/**
 * designator:
 *      '[' constant-expression ']'         (1)
 *      '.' IDENTIFIER                      (2)
 * 
 * No problems here.
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  DESIGNATOR_ARRAY,
  DESIGNATOR_FIELD
} designator_kind_t;

struct designator
{
  node_kind_t kind;
  designator_kind_t d_kind;
  union
  {
    struct constant_expression *ex;
    const char *str;
  };
  node_kind_t parent_kind;
  void *parent;
};

#endif
