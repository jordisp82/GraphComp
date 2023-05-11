#ifndef DECL_SPECS_T_H
#define DECL_SPECS_T_H

#include "ast_t.h"
#include "structs_t.h"
#include "stg_class_spec_t.h"
#include "type_qual_t.h"
#include "func_spec_t.h"

typedef struct decl_specs
{
  stg_class_spec_t stg_class_specs;
  /* TODO type specifier [0..N] */
  type_qual_t type_quals;
  func_spec_t func_specs;
  /* TODO alignment specifier [0..N] */
  ast_node_t *node;             /* parent must be directly a function definition */
} decl_specs_t;

#endif
