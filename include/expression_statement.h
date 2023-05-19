#ifndef EXPRESSION_STATEMENT_H
#define EXPRESSION_STATEMENT_H

/**
 * expression-statement:
 *      ';'         (1)
 *      expression ';'      (2)
 * 
 * No problems here.
 */

typedef enum
{
  NODE_EXPRESSION_STATEMENT
} node_kind_t;

typedef enum
{
  ES_EMPTY,
  ES_EXPRESSION
} es_kind_t;

struct expression;

struct expression_statement
{
  node_kind_t kind;             // NODE_EXPRESSION_STATEMENT
  es_kind_t es_kind;
  struct expression *expr;      // only for ES_EXPRESSION
  node_kind_t parent_kind;
  void *parent;
};

#endif
