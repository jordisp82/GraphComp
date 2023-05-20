#ifndef ASSIGNMENT_OPERATOR_H
#define ASSIGNMENT_OPERATOR_H

/**
 * assignment-operator:
 *      '='
 *      MUL_ASSIGN
 *      DIV_ASSIGN
 *      MOD_ASSIGN
 *      ADD_ASSIGN
 *      SUB_ASSIGN
 *      LEFT_ASSIGN
 *      RIGHT_ASSIGN
 *      AND_ASSIGN
 *      XOR_ASSIGN
 *      OR_ASSIGN
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  OP_EQUAL,
  OP_MUL_ASS,
  OP_DIV_ASS,
  OP_MOD_ASS,
  OP_ADD_ASS,
  OP_SUB_ASS,
  OP_LEFT_ASS,
  OP_RIGHT_ASS,
  OP_AND_ASS,
  OP_XOR_ASS,
  OP_OR_ASS
} assop_kind_t;

struct assignment_operator
{
  node_kind_t kind;
  assop_kind_t ass_op;
  node_kind_t parent_kind;
  void *parent;
};

#endif
