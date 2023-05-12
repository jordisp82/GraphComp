#ifndef DIRECT_ABS_DCLOR_T_H
#define DIRECT_ABS_DCLOR_T_H

#include "ast_t.h"
#include "structs_t.h"
#include "type_qual_t.h"

typedef enum
{
  DIRECT_ABS_DCLOR_DECLARATOR,
  DIRECT_ABS_DCLOR_ARRAY,
  DIRECT_ABS_DCLOR_FUNCTION
} direct_abs_dclor_kind_t;

typedef struct direct_abs_dlcor
{
  direct_abs_dclor_kind_t kind;
  union
  {
    struct abstract_dclor *abs_dclor;   /* DIRECT_ABS_DCLOR_DECLARATOR */
    struct
    {
      int is_asterisk;
      int is_static;
      type_qual_t type_quals;
      struct ass_expr *ass_expr;        /* may be NULL */
    } array;                    /* DIRECT_ABS_DCLOR_ARRAY */
    struct
    {
      struct param_type_list *param_list;       /* may be NULL */
    } function;                 /* DIRECT_ABS_DCLOR_FUNCTION */
  };
  struct direct_abs_dlcor *dir_abs_dclr;        /* may be NULL */
  ast_node_t *node;
} direct_abs_dlcor_t;

#endif
