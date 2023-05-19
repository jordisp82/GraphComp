#ifndef FUNCTION_DEFINITION_H
#define FUNCTION_DEFINITION_H

/**
 * function-definition:
 *      declaration-specifiers declarator declaration-list compound-statement       (1)
 *      declaration-specifiers declarator compound-statement        (2)
 * 
 * Declarator and compound-statement shouldn't be a problem.
 * declaration-specifiers is a combination of several things,
 * and they can include struct and union specifiers, which are
 * themselves a pain in the ass.
 * The declaration-list is, as its name clearly tells, a fucking list.
 */

typedef enum
{
  NODE_FUNCTION_DEFINITION
} node_kind_t;

typedef enum
{
  FD_K_AND_R,                   // K&R function definition
  FD_STANDARD_C                 // standard-C function definition
} fd_kind_t;

struct declaration_specifiers;
struct declarator;
struct declaration_list;
struct compound_statement;

struct function_definition
{
  node_kind_t kind;             // NODE_FUNCTION_DEFINITION
  fd_kind_t fd_kind;
  struct declaration_specifiers *ds;
  struct declarator *dr;
  struct declaration_list *dl;  // only non-NULL if fd_kind is FD_K_AND_R */
  struct compound_statement *cs;
  node_kind_t parent_kind;
  void *parent;                 /* void * for now */
};

#endif
