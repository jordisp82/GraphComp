#ifndef STATEMENT_H
#define STATEMENT_H

#include "sem_t.h"
#include "ast_t.h"

statement_t *sem_statement (ast_node_t * ast);

#endif
