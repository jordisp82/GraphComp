#ifndef ITERATION_STATEMENT_H
#define ITERATION_STATEMENT_H

/**
 * iteration-statement:
 *      WHILE '(' expression ')' statement              (1)
 *      DO statement WHILE '(' expression ')' ';'       (2)
 *      FOR '(' expression-statement expression-statement ')' statement     (3)
 *      FOR '(' expression-statement expression-statement expression ')' statement      (4)
 *      FOR '(' declaration expression-statement ')' statement              (5)
 *      FOR '(' declaration expression-statement expression ')' statement       (6)
 * 
 * parents:
 *      statement (5)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  IS_WHILE,
  IS_DO,
  IS_FOR_ES_ES,
  IS_FOR_ES_ES_EX,
  IS_FOR_DECL_ES,
  IS_FOR_DECL_ES_EX
} is_kind_t;

struct iteration_statement
{
  node_kind_t kind;
  is_kind_t is_kind;
  union
  {
    struct
    {
      struct expression *ex;
      struct statement *st;
    } is_while;
    struct
    {
      struct statement *st;
      struct expression *ex;
    } is_do;
    struct
    {
      struct expression_statement *es1;
      struct expression_statement *es2;
      struct statement *st;
    } is_for_es_es;
    struct
    {
      struct expression_statement *es1;
      struct expression_statement *es2;
      struct expression *ex;
      struct statement *st;
    } is_for_es_es_ex;
    struct
    {
      struct declaration *dl;
      struct expression_statement *es;
      struct statement *st;
    } is_for_decl_es;
    struct
    {
      struct declaration *dl;
      struct expression_statement *es;
      struct expression *ex;
      struct statement *st;
    } is_for_decl_es_ex;
  };
  void (*dot_create) (void *node, void *f);
  node_kind_t parent_kind;
  void *parent;
};

#endif
