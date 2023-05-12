#ifndef DIRECT_DCLOR_T_H
#define DIRECT_DCLOR_T_H

#include "ast_t.h"
#include "structs_t.h"
#include "type_qual_t.h"

typedef enum
{
  DIRECT_DCLOR_IDENT,
  DIRECT_DCLOR_DECLARATOR,
  DIRECT_DCLOR_ARRAY,
  DIRECT_DCLOR_FUNCTION
} direct_dclor_kind_t;

typedef struct direct_dclor
{
  direct_dclor_kind_t kind;
  union
  {
    const char *str;            /* DIRECT_DCLOR_IDENT */
    struct declarator *declarator;      /* DIRECT_DCLOR_DECLARATOR */
    struct
    {
      int is_asterisk;
      int is_static;
      type_qual_t type_quals;
      struct ass_expr *ass_expr;        /* may be NULL */
    } array;                    /* DIRECT_DCLOR_ARRAY */
    struct
    {
      struct param_type_list *param_list;       /* may be NULL */
      int n_ident_list;         /* may be zero */
      const char **strs;        /* may be NULL */
    } function;                 /* DIRECT_DCLOR_FUNCTION */
    struct direct_dclor *dir_dclor;     /* only NULL for DIRECT_DCLOR_IDENT and DIRECT_DCLOR_DECLARATOR */
  };
  ast_node_t *node;
} direct_dclor_t;

#endif
