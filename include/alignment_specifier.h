#ifndef ALIGNMENT_SPECIFIER_H
#define ALIGNMENT_SPECIFIER_H

/**
 * alignment-specifier:
 *      ALIGNAS '(' type-name ')'       (1)
 *      ALIGNAS '(' constant-expression ')'     (2)
 * 
 * parents:
 *      declaration-specifiers (9)(10)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  ALIGN_TYPE_NAME,
  ALIGN_CONST_EXPR
} align_kind_t;

struct alignment_specifier
{
  node_kind_t kind;
  align_kind_t a_kind;
  union
  {
    struct type_name *tn;
    struct constant_expression *expr;
  };
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
