#ifndef DIRECT_ABSTRACT_DECLARATOR_H
#define DIRECT_ABSTRACT_DECLARATOR_H

/**
 * direct-abstract-declarator:
 *      '(' abstract-declarator ')'                 (1)
 *      '[' ']'                 (2)
 *      '[' '*' ']'             (3)
 *      '[' STATIC type-qualifier-list assignment-expression ']'        (4)
 *      '[' STATIC assignment-expression ']'        (5)
 *      '[' type-qualifier-list STATIC assignment-expression ']'        (6)
 *      '[' type-qualifier-list assignment-expression ']'               (7)
 *      '[' type-qualifier-list ']'                 (8)
 *      '[' assignment-expression ']'               (9)
 *      direct-abstract-declarator '[' ']'          (10)
 *      direct-abstract-declarator '[' '*' ']'      (11)
 *      direct-abstract-declarator '[' STATIC type-qualifier-list assignment-expression ']'     (12)
 *      direct-abstract-declarator '[' STATIC assignment-expression ']'                         (13)
 *      direct-abstract-declarator '[' type-qualifier-list assignment-expression ']'            (14)
 *      direct-abstract-declarator '[' type-qualifier-list STATIC assignment-expression ']'     (15)
 *      direct-abstract-declarator '[' type-qualifier-list ']'          (16)
 *      direct-abstract-declarator '[' assignment-expression ']'        (17)
 *      '(' ')'                 (18)
 *      '(' parameter-type-list ')'                 (19)
 *      direct-abstract-declarator '(' ')'          (20)
 *      direct-abstract-declarator '(' parameter-type-list ')'          (21)
 * 
 * parents:
 *      abstract-declarator (1)(3)
 */

#include "node_kind_t.h"
#include "structs.h"

struct direct_abstract_declarator
{
  node_kind_t kind;
  int n_prod;
  struct abstract_declarator *adclr;
  struct type_qualifier_list *tql;
  struct assignment_expression *ass;
  struct parameter_type_list *ptl;
  struct direct_abstract_declarator *dad;
  node_kind_t parent_kind;
  void *parent;
};

#endif
