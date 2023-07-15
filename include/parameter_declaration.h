#ifndef PARAMETER_DECLARATION_H
#define PARAMETER_DECLARATION_H

/**
 * parameter-declaration:
 *      declaration-specifiers declarator           (1)
 *      declaration-specifiers abstract-declarator  (2)
 *      declaration-specifiers                      (3)
 * 
 * This is not a list.
 * 
 * parents:
 *      parameter-list (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
//#include "symbol.h"
#include "symtable.h"

typedef enum
{
  PD_DS_DECLR,
  PD_DS_ABS_DECLR,
  PD_DS
} pd_kind_t;

struct parameter_declaration
{
  node_kind_t kind;
  pd_kind_t pd_kind;
  struct declaration_specifiers *ds;
  union
  {
    struct declarator *dr;
    struct abstract_declarator *adr;
  };
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct parameter_declaration * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
symbol_t *create_symbol_for_param_declaration (struct parameter_declaration
                                               *buff);
void set_parameter_declaration_scope (struct parameter_declaration *buff);
#endif

#endif
