#ifndef RELATIONAL_EXPRESSION_H
#define RELATIONAL_EXPRESSION_H

/**
 * relational-expression:
 *      shift-expression            (1)
 *      relational-expression '<' shift-expression      (2)
 *      relational-expression '>' shift-expression      (3)
 *      relational-expression LE_OP shift-expression    (4)
 *      relational-expression GE_OP shift-expression    (5)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  REL_SHIFT,
  REL_LESS,
  REL_MORE,
  REL_EQ_LESS,
  REL_EQ_MORE
} rel_kind_t;

struct relational_expression
{
  node_kind_t kind;
  rel_kind_t rel_kind;
  struct shift_expression *sh_ex;
  struct relational_expression *relex;
  node_kind_t parent_kind;
  void *parent;
};

#endif
