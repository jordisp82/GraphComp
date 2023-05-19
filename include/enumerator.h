#ifndef ENUMERATOR_H
#define ENUMERATOR_H

/**
 * enumerator:
 *      enumeration-constant '=' constant-expression        (1)
 *      enumeration-constant        (2)
 */

typedef enum
{
  NODE_ENUMERATOR
} node_kind_t;

typedef enum
{
  ENUM_WITH_CONST_EXPR,
  ENUM_NO_CONST_EXPR
} enum_kind_t;

struct enumeration_constant;
struct constant_expression;

struct enumerator
{
  node_kind_t kind;
  enum_kind_t e_kind;
  struct enumeration_constant *ec;
  struct constant_expression *expr;
  node_kind_t parent_kind;
  void *parent;
};

#endif
