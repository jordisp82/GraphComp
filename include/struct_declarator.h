#ifndef STRUCT_DECLARATOR_H
#define STRUCT_DECLARATOR_H

/**
 * struct-declarator:
 *      ':' constant-expression         (1)
 *      declarator ':' constant-expression      (2)
 *      declarator                      (3)
 * 
 * parents:
 *      struct-declarator-list (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct struct_declarator
{
  node_kind_t kind;
  struct constant_expression *expr;
  struct declarator *dclr;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct struct_declarator * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_struct_declarator_scope (struct struct_declarator *buff);
#endif

#endif
