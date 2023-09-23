#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

/**
 * unary-operator:
 *      '&'
 *      '*'
 *      '+'
 *      '-'
 *      '~'
 *      '!'
 * 
 * parents:
 *      unary-expression (4)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  UNOP_AMPERSAND,
  UNOP_STAR,
  UNOP_PLUS,
  UNOP_DASH,
  UNOP_TILDE,
  UNOP_EXCLAMATION
} unop_kind_t;

struct unary_operator
{
  node_kind_t kind;
  unop_kind_t un_op;
  node_kind_t parent_kind;
  void *parent;
};

#endif
