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
  struct symtable *sym_table;
  void (*create_symtable) (struct declarator * buff);
  void (*create_symbol) (struct declarator * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
