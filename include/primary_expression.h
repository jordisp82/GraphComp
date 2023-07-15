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
//#include "symbol.h"
#include "symtable.h"

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
#if 0
  symbol_t *sym;                /* only for an identifier */
  node_kind_t scope_kind;
  void *scope;
#endif
  struct symtable *sym_table;
  void (*create_symtable) (struct primary_expression * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_primary_expression_scope (struct primary_expression *buff);
void set_symbol_for_primary_expression (struct primary_expression *buff);
#endif

#endif
