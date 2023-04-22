#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "declarator.h"
#include "ast.h"
#include "nonterms.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_pointers (declarator_t *dr, ast_node_t *ast);

declarator_t * sem_declarator (ast_node_t * ast)
{
    assert (ast != NULL);
    assert (ast->children != NULL);
    assert (IS_DECLARATOR (ast->func_ptr));
    
    declarator_t *dr = calloc (1, sizeof (declarator_t));
    assert (dr != NULL);
    
    if (IS_POINTER (ast->children[0]->func_ptr))
    {
        sem_pointers (dr, ast->children[0]);
    } else {
        dr->n_pointers = 0;
        dr->pointers = NULL;
        /* TODO */
    }
}

static void sem_pointers (declarator_t *dr, ast_node_t *ast)
{
    assert (dr != NULL);
    assert (ast != NULL);
    assert (IS_POINTER (ast->func_ptr));
    
    dr->n_pointers = 1;
}
