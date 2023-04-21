#ifndef DECL_SPECS_H
#define DECL_SPECS_H

#include "ast_t.h"

void sem_decl_specs (ast_node_t * ast);
void sem_type_spec (ast_node_t * ast);
void sem_type_qual (ast_node_t * ast);

#endif
