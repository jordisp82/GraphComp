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
 * 
 * parents:
 *      labeled-statement (1)(2)(3)
 *      block-item (2)
 *      selection-statement (1)(2)(3)
 *      iteration-statement (1)(2)(3)(4)(5)(6)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

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
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct statement * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_statement_scope (struct statement *buff);
void set_symbol_for_statement (struct statement *buff);
#endif

#endif
