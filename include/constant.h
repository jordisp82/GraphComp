#ifndef CONSTANT_H
#define CONSTANT_H

/**
 * constant:
 *      I_CONSTANT      (1)
 *      F_CONSTANT      (2)
 *      ENUMERATION_CONSTANT        (3)
 * 
 * parents:
 *      primary-expression (2)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  CONST_INTEGER,
  CONST_FLOAT,
  CONST_ENUM
} const_kind_t;

struct constant
{
  node_kind_t kind;
  const_kind_t const_kind;
  union
  {
    const char *string;
    int integer;
    double floating;
  };
  node_kind_t parent_kind;
  void *parent;
};

#endif
