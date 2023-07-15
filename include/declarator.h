#ifndef DECLARATOR_H
#define DECLARATOR_H

/**
 * declarator:
 *      pointer direct-declarator       (1)
 *      direct-declarator               (2)
 * 
 * parents:
 *      init-declarator (1)(2)
 *      struct-declarator (2)(3)
 *      direct-declarator (2)
 *      parameter-declaration (1)
 *      function-definition (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
//#include "symbol.h"
#include "symtable.h"

typedef enum
{
  DCLR_WITH_POINTER,
  DCLR_NO_POINTER
} dclr_kind_t;

struct declarator
{
  node_kind_t kind;
  dclr_kind_t dclr_kind;
  struct pointer *ptr;
  struct direct_declarator *ddclr;
#if 0
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct declarator * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
symbol_t *create_symbol_for_declarator (struct declarator *buff);
int create_symbols_for_parameters (struct declarator *buff,
                                   symbol_t *** sym_pars);
void set_declarator_scope (struct declarator *buff);
#endif

#endif
