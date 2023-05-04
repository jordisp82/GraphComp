#ifndef STATEMENT_H
#define STATEMENT_H

#include "nonterms.h"
#include "ast_t.h"

statement_t *sem_statement (ast_node_t * ast);

#endif
