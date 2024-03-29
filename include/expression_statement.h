#ifndef EXPRESSION_STATEMENT_H
#define EXPRESSION_STATEMENT_H

/**
 * expression-statement:
 *      ';'         (1)
 *      expression ';'      (2)
 * 
 * parents:
 *      statement (3)
 *      iteration-statement (3)(4)(5)(6)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  ES_EMPTY,
  ES_EXPRESSION
} es_kind_t;

struct expression_statement
{
  node_kind_t kind;             // NODE_EXPRESSION_STATEMENT
  es_kind_t es_kind;
  struct expression *expr;      // only for ES_EXPRESSION
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
