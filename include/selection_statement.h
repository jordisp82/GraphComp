#ifndef SELECTION_STATEMENT_H
#define SELECTION_STATEMENT_H

/**
 * selection-statement:
 *      IF '(' expression ')' statement ELSE statement      (1)
 *      IF '(' expression ')' statement                     (2)
 *      SWITCH '(' expression ')' statement                 (3)
 * 
 * parents:
 *      statement (4)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  SS_IF_ELSE,
  SS_IF,
  SS_SWITCH
} ss_kind_t;

struct selection_statement
{
  node_kind_t kind;
  ss_kind_t ss_kind;
  struct expression *ex;
  struct statement *st1;
  struct statement *st2;        // only if SS_IF_ELSE
  node_kind_t parent_kind;
  void *parent;
};

#endif
