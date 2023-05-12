#ifndef INIT_DECLARATOR_T_H
#define INIT_DECLARATOR_T_H

#include "ast_t.h"
#include "structs_t.h"

struct init_declr
{
  struct declarator *declr;     /* mandatory */
  struct initzer *initzer;      /* optional */
  ast_node_t *node;
} init_declr_t;

#endif
