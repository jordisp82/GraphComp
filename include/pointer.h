#ifndef POINTER_H
#define POINTER_H

/**
 * pointer:
 *      '*' type-qualifier-list pointer     (1)
 *      '*' type-qualifier-list             (2)
 *      '*' pointer
 *      '*'
 * 
 * This is NOT a list.
 */

typedef enum
{
  NODE_POINTER
} node_kind_t;

typedef enum
{
  PTR_TQ_PTR,
  PTR_TQ,
  PTR_PTR,
  PTR_EMPTY
} pointer_kind_t;

struct type_qualifier_list;

struct pointer
{
  node_kind_t kind;
  pointer_kind_t ptr_kind;
  struct type_qualifier_list *tql;
  struct pointer *ptr;
  node_kind_t parent_kind;
  void *parent;
};

#endif
