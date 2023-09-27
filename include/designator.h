#ifndef DESIGNATOR_H
#define DESIGNATOR_H

/**
 * designator:
 *      '[' constant-expression ']'         (1)
 *      '.' IDENTIFIER                      (2)
 * 
 * parents:
 *      designator-list (1)(2)
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
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
