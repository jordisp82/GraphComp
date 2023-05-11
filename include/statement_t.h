#ifndef STATEMENT_T_H
#define STATEMENT_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  STMT_LABELED,
  STMT_COMPOUND,
  STMT_EXPRESSION,
  STMT_SELECTION,
  STMT_ITERATION,
  STMT_JUMP
} stmt_kind_t;

typedef struct statement
{
  stmt_kind_t kind;
  union
  {
    struct label_stmt *label;   /* STMT_LABELED */
    struct compound_stmt *comp; /* STMT_COMPOUND */
    struct expression *expr;    /* STMT_EXPRESSION, may be NULL */
    struct select_stmt *select; /* STMT_SELECTION */
    struct iteration_stmt *iter;        /* STMT_ITERATION */
    struct jump_stmt *jump;     /* STMT_JUMP */
  };
  ast_node_t *node;
} statement_t;

#endif
