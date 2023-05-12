#ifndef PARAM_TYPE_LIST_T_H
#define PARAM_TYPE_LIST_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct param_type_list
{
  int n_param_decls;
  struct param_decl *param_decls;
  int variadic;
  ast_node_t *node;
} param_type_list_t;

#endif
