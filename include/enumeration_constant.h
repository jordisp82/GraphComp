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

struct enumeration_constant
{
  node_kind_t kind;
  const char *str;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

extern void add_enumeration_constant (const char *str);

#endif
