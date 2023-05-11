#ifndef FUNC_DEF_T_H
#define FUNC_DEF_T_H

#include "ast_t.h"
#include "structs_t.h"
#include "decl_specs_t.h"

typedef struct func_def
{
  decl_specs_t *decl_specs;     /* mandatory */
  struct declarator *declr;     /* mandatory */
  struct decltion_list *decln_list;     /* only for K&R defintions */
  struct compound_stmt *comp_stmt;      /* mandatory */
  ast_node_t *node;
} func_def_t;

#endif
