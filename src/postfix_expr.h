#ifndef POSTFIX_EXPR_H
#define POSTFIX_EXPR_H

#include "nonterms.h"
#include "ast_t.h"

postfix_expr_t *sem_postfix_expr (ast_node_t * ast);

#endif
