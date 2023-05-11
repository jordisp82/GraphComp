#ifndef LABEL_STMT_T_H
#define LABEL_STMT_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  LABEL_LABEL,
  LABEL_CASE,
  LABEL_DEFAULT
} label_kind_t;

typedef struct label_stmt
{
  label_kind_t kind;
  const char *str;              /* LABEL_LABEL */
  struct const_expr *expr;      /* LABEL_CASE */
  struct statement *stmt;       /* LABEL_LABEL, LABEL_CASE, LABEL_DEFAULT */
  ast_node_t *node;
} label_stmt_t;

#endif
