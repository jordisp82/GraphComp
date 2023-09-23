#ifndef LABELED_STATEMENT_H
#define LABELED_STATEMENT_H

/**
 * labeled-statement:
 *      IDENTIFIER ':' statement        (1)
 *      CASE constant-expression ':' statement      (2)
 *      DEFAULT ':' statement           (3)
 * 
 * parents:
 *      statement (1)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  LABEL_IDENTIFIER,
  LABEL_CASE,
  LABEL_DEFAULT
} ls_kind_t;

struct labeled_statement
{
  node_kind_t kind;             // NODE_LABELED_STATEMENT
  ls_kind_t ls_kind;
  union
  {
    const char *id;             // only for LABEL_IDENTIFIER
    struct constant_expression *ce;     // only for LABEL_CASE
  };
  struct statement *s;
  node_kind_t parent_kind;
  void *parent;
};

#endif
