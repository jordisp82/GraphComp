#ifndef STRING_SYMBOL_H
#define STRING_SYMBOL_H

/**
 * string:
 *      STRING_LITERAL      (1)
 *      FUNC_NAME           (2)
 * 
 * parents:
 *      primary-expression (3)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  STRING_STRING,
  STRING_FUNC_NAME
} string_kind_t;

struct string
{
  node_kind_t kind;
  string_kind_t str_kind;
  const char *str;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
