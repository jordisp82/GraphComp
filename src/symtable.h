#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "ast_t.h"

typedef struct __symbol
{
  const char *name;             /* name of the "thing" */
  ast_node_t *decl;             /* where the "thing" has been declared */
  struct __symbol *next;
} symbol_t;

typedef struct __symnode
{
  symbol_t *list;               /* list of symbols */
  struct __symnode *parent;     /* NULL if root parent */
  ast_node_t *scope;            /* NULL if file scope */
  int n_children;
  struct __symnode **children;
} sym_node_t;

sym_node_t *create_symtable (ast_node_t * tu);

#endif
