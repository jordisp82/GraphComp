#ifndef DECLTION_LIST_T_H
#define DECLTION_LIST_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct decltion_list
{
  int n_declarations;
  struct declaration **declarations;
  ast_node_t *node;
} decltion_list_t;

#endif
