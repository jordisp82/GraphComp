#ifndef TYPE_NAME_T_H
#define TYPE_NAME_T_H

#include "ast_t.h"
#include "structs_t.h"
#include "type_qual_t.h"

typedef struct type_name
{
  /* specifier-qualifier-list *//* mandatory *//* type-specifier */
  type_qual_t type_quals;
  struct abstract_dclor *abs_dclor;     /* optional */
  ast_node_t *node;
} type_name_t;

#endif
