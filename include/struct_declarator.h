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

struct struct_declarator
{
  node_kind_t kind;
  struct constant_expression *expr;
  struct declarator *dclr;
  node_kind_t parent_kind;
  void *parent;
};

#endif
