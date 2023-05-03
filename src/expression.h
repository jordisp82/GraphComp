#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "nonterms.h"
#include "ast_t.h"

expression_t *sem_expression (ast_node_t * ast);

#endif
