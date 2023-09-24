#ifndef INITIALIZER_H
#define INITIALIZER_H

/**
 * initializer:
 *      '{' initializer-list '}'        (1)
 *      '{' initializer-list ',' '}'    (2)
 *      assignment-expression           (3)
 * 
 * parents:
 *      init-declarator (1)
 *      initializer-list (1)(2)(3)(4)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  IN_LIST,
  IN_ASS_EXPR
} in_kind_t;

struct initializer
{
  node_kind_t kind;
  in_kind_t child_kind;
  union
  {
    struct initializer_list *il;
    struct assignment_expression *ae;
  };
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
