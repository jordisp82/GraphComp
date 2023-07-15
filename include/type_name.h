#ifndef TYPE_NAME_H
#define TYPE_NAME_H

/**
 * type-name:
 *      specifier-qualifier-list abstract-declarator        (1)
 *      specifier-qualifier-list            (2)
 * 
 * parents:
 *      ignoring generic-association
 *      postfix-expression (9)(10)
 *      unary-expression (6)(7)
 *      cast-expression (2)
 *      atomic-type-specifier (1)
 *      alignment-specifier (1)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct type_name
{
  node_kind_t kind;
  struct specifier_qualifier_list *sql;
  struct abstract_declarator *adlr;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct type_name * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_type_name_scope (struct type_name *buff);
#endif

#endif
