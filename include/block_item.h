#ifndef BLOCK_ITEM_H
#define BLOCK_ITEM_H

/**
 * block-item:
 *      declaration     (1)
 *      statement       (2)
 * 
 * No problems here.
 */

typedef enum
{
  NODE_BLOCK_ITEM,
  NODE_DECLARATION,
  NODE_STATEMENT
} node_kind_t;

struct declaration;
struct statement;

struct block_item
{
  node_kind_t kind;             // NODE_BLOCK_ITEM
  node_kind_t child_kind;
  union
  {
    struct declaration *d;
    struct statement *s;
  };
  node_kind_t parent_kind;
  void *parent;
};

#endif
