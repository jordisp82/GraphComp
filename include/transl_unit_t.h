#ifndef TRANSL_UNIT_T_H
#define TRANSL_UNIT_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct transl_unit
{
  int n_children;
  struct extern_def **children;
  ast_node_t *node;
} transl_unit_t;

#endif
