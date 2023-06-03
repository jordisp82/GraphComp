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
 * parents:
 *      statement (6)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  JS_GOTO,
  JS_CONTINUE,
  JS_BREAK,
  JS_RETURN_VOID,
  JS_RETURN_EXP
} js_kind_t;

struct jump_statement
{
  node_kind_t kind;
  js_kind_t js_kind;
  union
  {
    const char *id;             // only JS_GOTO
    struct expression *exp;     // only JS_RETURN_EXP
  };
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_jump_statetment_scope (struct jump_statement *buff);
void fill_in_symtable_jump_stmt (struct jump_statement *buff);

#endif
