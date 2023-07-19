#ifndef ENUMERATION_CONSTANT_H
#define ENUMERATION_CONSTANT_H

/**
 * enumeration-constant:
 *      IDENTIFIER
 * 
 * parents:
 *      enumerator (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct enumeration_constant
{
  node_kind_t kind;
  const char *str;
  struct symtable *sym_table;
  void (*create_symtable) (struct enumeration_constant * buff);
  void (*create_symbol) (struct enumeration_constant * buff);
  node_kind_t parent_kind;
  void *parent;
};

extern void add_enumeration_constant (const char *str);

#endif
