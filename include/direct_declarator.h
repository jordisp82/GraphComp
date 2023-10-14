#ifndef DIRECT_DECLARATOR_H
#define DIRECT_DECLARATOR_H

/**
 * direct-declarator:
 *      IDENTIFIER                          (1)
 *      '(' declarator ')'                  (2)
 *      direct-declarator '[' ']'           (3)
 *      direct-declarator '[' '*' ']'       (4)
 *      direct-declarator '[' STATIC type-qualifier-list assignment-expression ']'      (5)
 *      direct-declarator '[' STATIC assignment-expression ']'                          (6)
 *      direct-declarator '[' type-qualifier-list '*' ']'                               (7)
 *      direct-declarator '[' type-qualifier-list STATIC assignment-expression ']'      (8)
 *      direct-declarator '[' type-qualifier-list assignment-expression ']'             (9)
 *      direct-declarator '[' type-qualifier-list ']'           (10)
 *      direct-declarator '[' assignment-expression ']'         (11)
 *      direct-declarator '(' parameter-type-list ')'           (12)
 *      direct-declarator '(' ')'           (13)
 *      direct-declarator '(' identifier-list ')'               (14)
 * 
 * parents:
 *      declarator (1), (2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "type_t.h"

struct direct_declarator
{
  node_kind_t kind;
  int n_prod;
  const char *id;
  struct declarator *declr;
  struct direct_declarator *ddeclr;
  struct type_qualifier_list *tql;
  struct assignment_expression *ass;
  struct parameter_type_list *ptl;
  struct identifier_list *il;
  void (*dot_create) (void *node, void *f);
  /* NOTE start of experimental code */
  int (*sem_analysis) (void *node);
  type_t type;
  /* NOTE end of experimental code */
  node_kind_t parent_kind;
  void *parent;
};

#endif
