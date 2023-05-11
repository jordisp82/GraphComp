#ifndef JUMP_STMT_T_H
#define JUMP_STMT_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  JUMP_GOTO,
  JUMP_CONTINUE,
  JUMP_BREAK,
  JUMP_RETURN
} jump_kind_t;

typedef struct jump_stmt
{
  jump_kind_t kind;
  const char *label;            /* JUMP_GOTO */
  struct expression *expr;      /* optional for JUMP_RETURN */
  ast_node_t *node;
} jump_stmt_t;

#endif
