#ifndef JUMP_STATEMENT_H
#define JUMP_STATEMENT_H

/**
 * jump-statement:
 *      GOTO IDENTIFIER ';'             (1)
 *      CONTINUE ';'                    (2)
 *      BREAK ';'                       (3)
 *      RETURN ';'                      (4)
 *      RETURN expression ';'           (5)
 * 
 * No problems here.
 */

typedef enum
{
  NODE_JUMP_STATEMENT
} node_kind_t;

typedef enum
{
  JS_GOTO,
  JS_CONTINUE,
  JS_BREAK,
  JS_RETURN_VOID,
  JS_RETURN_EXP
} js_kind_t;

struct expression;

struct jump_statement
{
  node_kind_t kind;
  js_kind_t js_kind;
  union
  {
    const char *id;             // only JS_GOTO
    struct expression *exp;     // only JS_RETURN_EXP
  };
  node_kind_t parent_kind;
  void *parent;
};

#endif
