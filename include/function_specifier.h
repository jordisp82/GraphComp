#ifndef FUNCTION_SPECIFIER_H
#define FUNCTION_SPECIFIER_H

/**
 * function-specifier:
 *      INLINE      (1)
 *      NORETURN    (2)
 * 
 * parents:
 *      declaration-specifiers (7)(8)
 */

#include "node_kind_t.h"
#include "symtable.h"

typedef enum
{
  FS_INLINE,
  FS_NORETURN
} fs_kind_t;

struct function_specifier
{
  node_kind_t kind;
  fs_kind_t fs_kind;
  struct symtable *sym_table;
  void (*create_symtable) (struct function_specifier * buff);
  void (*create_symbol) (struct function_specifier * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
