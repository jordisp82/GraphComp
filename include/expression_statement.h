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
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_expression_stmt_scope (struct expression_statement *buff);
void set_symbol_for_expression_stmt (struct expression_statement *buff);

#endif
