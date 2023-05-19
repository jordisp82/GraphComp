#ifndef EXTERNAL_DECLARATION_H
#define EXTERNAL_DECLARATION_H

/**
 * external-declaration:
 *      function-definition     (1)
 *      declaration             (2)
 * 
 * No problems here. We have either the one
 * or the other.
 */

typedef enum
{
  NODE_EXTERNAL_DECLARATION,
  NODE_FUNCTION_DEFINITION,
  NODE_DECLARATION
} node_kind_t;

struct function_definition;
struct declaration;

struct external_declaration
{
  node_kind_t kind;             // NODE_EXTERNAL_DECLARATION
  node_kind_t child_kind;
  union
  {
    struct function_definition *fd;
    struct declaration *d;
  };
  node_kind_t parent_kind;
  void *parent;
};

#endif
