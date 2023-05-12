#ifndef ENUMERATOR_T_H
#define ENUMERATOR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct enumerator
{
  const char *enum_const;       /* mandatory */
  struct const_expr *const_expr;        /* optional */
  ast_node_t *node;
} enumerator_t;

#endif
