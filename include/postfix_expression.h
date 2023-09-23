#ifndef POSTFIX_EXPRESSION_H
#define POSTFIX_EXPRESSION_H

/**
 * postfix-expression:
 *      primary-expression                          (1)
 *      postfix-expression '[' expression ']'       (2)
 *      postfix-expression '(' ')'                  (3)
 *      postfix-expression '(' argument-expression-list ')'     (4)
 *      postfix-expression '.' IDENTIFIER           (5)
 *      postfix-expression PTR_OP IDENTIFIER        (6)
 *      postfix-expression INC_OP                   (7)
 *      postfix-expression DEC_OP                   (8)
 *      '(' type-name ')' '{' initializer-list '}'  (9)
 *      '(' type-name ')' '{' initializer-list ',' '}'          (10)
 * 
 * parents:
 *      unary-expression (1)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  POSTFIX_PRIMARY,
  POSTFIX_ARRAY,
  POSTFIX_FUNCTION,
  POSTFIX_FIELD1,
  POSTFIX_FIELD2,
  POSTFIX_INC,
  POSTFIX_DEC,
  POSTFIX_COMP_LIT
} postfix_kind_t;

struct postfix_expression
{
  node_kind_t kind;
  postfix_kind_t pf_kind;
  struct postfix_expression *pfex;
  const char *id;
  union
  {
    struct primary_expression *pex;
    struct expression *ex;
    struct argument_expression_list *ael;
    struct
    {
      struct type_name *tn;
      struct initializer_list *il;
    } comp_lit;
  };
  node_kind_t parent_kind;
  void *parent;
};

#endif
