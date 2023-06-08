#ifndef PRIMARY_EXPRESSION_H
#define PRIMARY_EXPRESSION_H

/**
 * primary-expression:
 *      IDENTIFIER              (1)
 *      constant                (2)
 *      string                  (3)
 *      '(' expression ')'      (4)
 *      generic-selection       (5)
 * 
 * parents:
 *      postfix-expression (1)
 * 
 * We're going to ignore generic-selection.
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symbol.h"

typedef enum
{
  PRIEX_IDENT,
  PRIEX_CONST,
  PRIEX_STRING,
  PRIEX_EX,
  PRIEX_GS
} priex_kind_t;

struct primary_expression
{
  node_kind_t kind;
  priex_kind_t priex_kind;
  union
  {
    const char *id;
    struct constant *c;
    struct string *s;
    struct expression *e;
  };
  symbol_t *sym;                /* only for an identifier */
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

void set_primary_expression_scope (struct primary_expression *buff);
void set_symbol_for_primary_expression (struct primary_expression *buff);

#endif
