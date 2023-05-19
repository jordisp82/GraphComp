#ifndef TYPE_QUALIFIER_H
#define TYPE_QUALIFIER_H

/**
 * type-qualifier:
 *      CONST       (1)
 *      RESTRICT    (2)
 *      VOLATILE    (3)
 *      ATOMIC      (4)
 */

typedef enum
{
  NODE_TYPE_QUALIFIER
} node_kind_t;

typedef enum
{
  TQ_CONST,
  TQ_RESTRICT,
  TQ_VOLATILE,
  TQ_ATOMIC
} tq_kind_t;

struct type_qualifier
{
  node_kind_t kind;
  tq_kind_t tq_kind;
  node_kind_t parent_kind;
  void *parent;
};

#endif
