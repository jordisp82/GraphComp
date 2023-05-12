#ifndef DESIGNATOR_T_H
#define DESIGNATOR_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  DESIGNR_ARRAY,
  DESIGNR_FIELD
} designr_kind_t;

typedef struct designator
{
  designr_kind_t kind;
  union
  {
    struct const_expr *const_expr;      /* DESIGNR_ARRAY [ expr ] */
    const char *str;            /* DESIGNR_FIELD . IDENTIFIER */
  };
  ast_node_t *node;
} designator_t;

#endif
