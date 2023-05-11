#ifndef SELECT_STMT_T_H
#define SELECT_STMT_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  SELECT_IF,
  SELECT_IF_ELSE,
  SELECT_SWITCH
} select_kind_t;

typedef struct select_stmt
{
  select_kind_t kind;
  struct expression *expr;      /* if or switch controlling expression */
  struct statement *st1;        /* switch or if branch is taken */
  struct statement *st2;        /* else branch is taken */
  ast_node_t *node;
} select_stmt_t;

#endif
