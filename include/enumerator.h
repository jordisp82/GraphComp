#ifndef ENUMERATOR_H
#define ENUMERATOR_H

/**
 * enumerator:
 *      enumeration-constant '=' constant-expression        (1)
 *      enumeration-constant        (2)
 * 
 * parents:
 *      enumerator-list (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  ENUM_WITH_CONST_EXPR,
  ENUM_NO_CONST_EXPR
} enum_kind_t;

struct enumerator
{
  node_kind_t kind;
  enum_kind_t e_kind;
  struct enumeration_constant *ec;
  struct constant_expression *expr;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_enumerator_scope (struct enumerator *buff);

#endif
