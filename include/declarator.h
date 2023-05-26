#ifndef DECLARATOR_H
#define DECLARATOR_H

/**
 * declarator:
 *      pointer direct-declarator       (1)
 *      direct-declarator               (2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symbol.h"

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
  node_kind_t parent_kind;
  void *parent;
};

symbol_t *create_symbol_for_declarator (struct declarator *buff);

#endif
