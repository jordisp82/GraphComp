#ifndef DECLARATOR_T_H
#define DECLARATOR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct declarator
{
  struct pointer *pointer;      /* optional */
  struct direct_dclor *__direct_dclor;  /* mandatory */
  ast_node_t *node;
} declarator_t;

#endif
