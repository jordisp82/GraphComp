#ifndef PARAMETER_LIST_H
#define PARAMETER_LIST_H

/**
 * parameter-list:
 *      parameter-declaration       (1)
 *      parameter-list ',' parameter-declaration        (2)
 * 
 * This is a list.
 */

typedef enum
{
  NODE_PARAMETER_LIST
} node_kind_t;

struct parameter_declaration;

struct parameter_list
{
  node_kind_t kind;
  struct pl_node
  {
    struct parameter_declaration *pd;
    struct pl_node *next;
  } *first, *last;
  node_kind_t parent_kind;
  void *parent;
};

#endif
