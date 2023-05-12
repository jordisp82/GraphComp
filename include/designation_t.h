#ifndef DESIGNATION_T_H
#define DESIGNATION_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct designation
{
  int n_designators;
  struct designator **designators;
  ast_node_t *node;
} designation_t;

#endif
