#ifndef ITER_STMT_T_H
#define ITER_STMT_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  ITER_WHILE,
  ITER_DO,
  ITER_FOR_1,
  ITER_FOR_2,
  ITER_FOR_3,
  ITER_FOR_4
} iter_kind_t;

typedef struct iteration_stmt
{
  iter_kind_t kind;
  struct expression *expr;      /* ITER_WHILE, ITER_DO, ITER_FOR_2, ITER_FOR_4 */
  struct statement *stmt;       /* all */
  struct statement *es1;        /* all ITER_FOR, it must be expression statement */
  struct statement *es2;        /* ITER_FOR_1, ITER_FOR_2, it must be expression statement */
  struct declaration *decl;     /* ITER_FOR_3, ITER_FOR_4 */
  ast_node_t *node;
} iter_stmt_t;

#endif
