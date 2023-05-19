#ifndef STATIC_ASSERT_DECLARATION_H
#define STATIC_ASSERT_DECLARATION_H

/**
 * static_assert-declaration:
 *      STATIC_ASSERT '(' constant-expression ',' STRING_LITERAL ')' ';'
 * 
 * No problems here.
 */

typedef enum
{
  NODE_STATIC_ASSERT_DECLARATION
} node_kind_t;

struct constant_expression;

struct static_assert_declaration
{
  node_kind_t kind;
  struct constant_expression *expr;
  const char *str;
  node_kind_t parent_kind;
  void *parent;
};

#endif
