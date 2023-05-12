#ifndef INITZER_BLOCK_T_H
#define INITZER_BLOCK_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct initzer_block
{
  struct designation *designation;      /* optional */
  struct initzer *initzer;      /* mandatory */
  ast_node_t *node;
} initzer_block_t;

#endif
