#ifndef PARAMETER_DECLARATION_H
#define PARAMETER_DECLARATION_H

/**
 * parameter-declaration:
 *      declaration-specifiers declarator           (1)
 *      declaration-specifiers abstract-declarator  (2)
 *      declaration-specifiers                      (3)
 * 
 * This is not a list.
 */

#include "node_kind_t.h"
#include "structs.h"

typedef enum
{
  PD_DS_DECLR,
  PD_DS_ABS_DECLR,
  PD_DS
} pd_kind_t;

struct parameter_declaration
{
  node_kind_t kind;
  pd_kind_t pd_kind;
  struct declaration_specifiers *ds;
  union
  {
    struct declarator *dr;
    struct abstract_declarator *adr;
  };
  node_kind_t parent_kind;
  void *parent;
};

#endif
