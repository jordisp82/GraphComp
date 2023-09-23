#ifndef FUNCTION_DEFINITION_H
#define FUNCTION_DEFINITION_H

/**
 * function-definition:
 *      declaration-specifiers declarator declaration-list compound-statement       (1)
 *      declaration-specifiers declarator compound-statement        (2)
 * 
 * parent:
 *      external-declaration (?)
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  FD_K_AND_R,                   // K&R function definition
  FD_STANDARD_C                 // standard-C function definition
} fd_kind_t;

struct function_definition
{
  node_kind_t kind;
  fd_kind_t fd_kind;
  struct declaration_specifiers *ds;
  struct declarator *dr;
  struct declaration_list *dl;  // only non-NULL if fd_kind is FD_K_AND_R */
  struct compound_statement *cs;
  node_kind_t parent_kind;
  void *parent;
};

#endif
