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

typedef enum
{
  FS_INLINE,
  FS_NORETURN
} fs_kind_t;

struct function_specifier
{
  node_kind_t kind;
  fs_kind_t fs_kind;
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
