#ifndef SYMBOL_H
#define SYMBOL_H

#include "node_kind_t.h"

#if 0
typedef enum
{
  NS_LABELS,
  NS_TAGS,
  NS_ORDINARY
} namespace_t;
#endif

/*
 * No type for scopes, since each scope is
 * defined by the correspondig AST node.
 * It can be a translation unit (file scope),
 * a compound statement or iteration statement
 * (block scope), and a function definition
 * (function scope, only for labels).
 */

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
