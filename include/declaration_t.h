#ifndef DECLARATION_T_H
#define DECLARATION_T_H

#include "ast_t.h"
#include "structs_t.h"

/*
 * If s_ass_d is not NULL,
 * the other fields shall be NULL.
 * If s_ass_d is NULL,
 * the other fields shall not be NULL.
 * At least one of the fiels
 * shall not be NULL.
 */

typedef struct declaration
{
  union
  {
    struct static_assert_decl *s_ass_d;
    struct
    {
      struct decl_specs *decl_specs;    /* mandatory */
      struct init_decl_list *init_decl_list;    /* optional */
    };
  };
  ast_node_t *node;
} declaration_t;

#endif
