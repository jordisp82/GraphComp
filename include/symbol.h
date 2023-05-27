#ifndef SYMBOL_H
#define SYMBOL_H

#include "node_kind_t.h"
#include "structs.h"

/*
 * A name can be declared by a declaration,
 * or a function definition, or a label.
 */

typedef enum
{
  SYM_NS_ORDINARY,
  SYM_NS_TYPEDEF,
  SYM_NS_TAG,
} sym_ns_t;

/*
 * NOTE FIXME
 * For ordinary namespace, point to the declarator.
 * For tag namespace, point to the struct or union specifier.
 * For typedef namespace, point to the declarator.
 */

typedef struct symbol
{
  const char *name;
  sym_ns_t sym_ns;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t tag_kind;         /* to distinguish between struct/union and enum */
  union
  {
    struct declarator *dclr;
    struct struct_or_union_specifier *sus;
    struct enum_specifier *es;
  };
} symbol_t;

#endif
