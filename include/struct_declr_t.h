#ifndef STRUCT_DECLR_T_H
#define STRUCT_DECLR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct struct_declr
{
  /* both can't be NULL at the same time */
  struct const_expr *const_expr;        /* may be NULL */
  struct declarator *declarator;        /* may be NULL */
  ast_node_t *node;
} struct_declr_t;

#endif
