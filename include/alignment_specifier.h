#ifndef ALIGNMENT_SPECIFIER_H
#define ALIGNMENT_SPECIFIER_H

/**
 * alignment-specifier:
 *      ALIGNAS '(' type-name ')'       (1)
 *      ALIGNAS '(' constant-expression ')'     (2)
 * 
 * No problem.
 */

typedef enum
{
  NODE_ALIGNMENT_SPECIFIER
} node_kind_t;

typedef enum
{
  ALIGN_TYPE_NAME,
  ALIGN_CONST_EXPR
} align_kind_t;

struct type_name;
struct constant_expression;

struct alignment_specifier
{
  node_kind_t kind;
  align_kind_t a_kind;
  union
  {
    struct type_name *tn;
    struct constant_expression *expr;
  };
  node_kind_t parent_kind;
  void *parent;
};

#endif
