#ifndef STRUCT_DECL_T_H
#define STRUCT_DECL_T_H

#include "ast_t.h"
#include "structs_t.h"
#include "type_qual_t.h"

typedef struct struct_decl
{
  struct type_spec *type_specs;
  type_qual_t type_quals;
  int n_struct_declrs;
  struct struct_declr **struct_declrs;
  /* NOTE fuck off static assert declaration */
  ast_node_t *ast;
} struct_decl_t;

#endif
