#ifndef POINTER_T_H
#define POINTER_T_H

#include "ast_t.h"
#include "structs_t.h"
#include "type_qual_t.h"

typedef struct pointer
{
  type_qual_t type_quals;
  struct pointer *pointer;      /* may be NULL */
  ast_node_t *node;
} pointer_t;

#endif
