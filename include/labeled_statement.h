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
#include "symtable.h"

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
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct labeled_statement * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_labeled_stmt_scope (struct labeled_statement *buff);
void set_symbol_for_labeled_statement (struct labeled_statement *buff);
#endif

#endif
