#ifndef ADDITIVE_EXPRESSION
#define ADDITIVE_EXPRESSION

/**
 * additive-expression:
 *      multiplicative-expression       (1)
 *      additive-expression '+' multiplicative-expression       (2)
 *      additive-expression '-' multiplicative-expression       (3)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  ADD_NONE,
  ADD_PLUS,
  ADD_MINUS
} add_kind_t;

struct additive_expression
{
  node_kind_t kind;
  add_kind_t add_kind;
  struct multiplicative_expression *mult_ex;
  struct additive_expression *add_ex;
  node_kind_t parent_kind;
  void *parent;
};

#endif
