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
  SYM_NS_TAG,
} sym_ns_t;

/*
 * For ordinary namespace, point to the declarator.
 * For tag namespace, point to the struct or union specifier.
 */

typedef struct symbol
{
  const char *name;
  sym_ns_t sym_ns;
  void *node;
  node_kind_t node_kind;
#if 0
  node_kind_t tag_kind;         /* to distinguish between struct/union and enum */
  union
  {
    struct declarator *dclr;
    struct struct_or_union_specifier *sus;
    struct enum_specifier *es;
  };
#endif
  struct symbol *misra_5_3;     /* inner symbol, the one that hides the other symbol */
  struct symbol *misra_5_6;
  struct symbol *misra_5_7;
} symbol_t;

#endif
