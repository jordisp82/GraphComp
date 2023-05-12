#ifndef PARAM_DECL_T_H
#define PARAM_DECL_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct param_decl
{
  struct decl_specs *decl_specs;        /* mantatory */
  struct declarator *declarator;        /* may be NULL */
  struct abstract_dclor *abs_dclor;     /* may be NULL */
  /* declarator and abs_dclor shall not be non-NULL both at the same time */
  ast_node_t *node;
} param_decl_t;

#endif
