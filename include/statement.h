#ifndef STATEMENT_H
#define STATEMENT_H

/**
 * statement:
 *      labeled-statement           (1)
 *      compound-statement          (2)
 *      expression-statement        (3)
 *      selection-statement         (4)
 *      iteration-statement         (5)
 *      jump-statement              (6)
 */

#include "node_kind_t.h"
#include "structs.h"

struct statement
{
  node_kind_t kind;
  node_kind_t child_kind;
  union
  {
    struct labeled_statement *ls;
    struct compound_statement *cs;
    struct expression_statement *es;
    struct selection_statement *ss;
    struct iteration_statement *is;
    struct jump_statement *js;
  };
  node_kind_t parent_kind;
  void *parent;
};

#endif
