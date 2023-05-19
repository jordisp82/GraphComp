#ifndef FUNCTION_SPECIFIER_H
#define FUNCTION_SPECIFIER_H

/**
 * function-specifier:
 *      INLINE      (1)
 *      NORETURN    (2)
 */

typedef enum
{
  NODE_FUNCTION_SPECIFIER
} node_kind_t;

typedef enum
{
  FS_INLINE,
  FS_NORETURN
} fs_kind_t;

struct function_specifier
{
  node_kind_t kind;
  fs_kind_t fs_kind;
  node_kind_t parent_kind;
  void *parent;
};

#endif
