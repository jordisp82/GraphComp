#ifndef DIRECT_ABS_DCLOR_T_H
#define DIRECT_ABS_DCLOR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct abstract_dclor
{
  /* at least one shall not be NULL */
  struct pointer *pointer;
  struct direct_abs_dlcor *direct_abs_dlcor;
  ast_node_t *node;
} abstract_dclor_t;

#endif
