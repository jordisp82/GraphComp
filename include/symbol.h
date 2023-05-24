#ifndef SYMBOL_H
#define SYMBOL_H

#include "node_kind_t.h"

/*
 * A name can be declared by a declaration,
 * or a function definition, or a label.
 */

typedef struct symbol
{
  const char *name;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t declaration_kind;
  void *declaration;
} symbol_t;

#endif
