#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "symbol.h"

/*
 * struct and union fields won't be stored into
 * the symbol table; they belong to their type
 * definition.
 */

/*
 * TODO replace void * for tree *
 * when the AVL tree is implemented
 */
struct symtable
{
    void *ns_labels;
    void *ns_tags;
    void *ns_ordinary;
};

#endif
