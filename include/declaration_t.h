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
      int n_init_declrs;        /* may be zero */
      struct init_declr **init_declrs;  /* may be NULL */
      /* NOTE fuck off static_assert_decl */
    };
  };
  ast_node_t *node;
} declaration_t;

#endif
