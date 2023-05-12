#ifndef STRUCT_UNION_SPEC_T_H
#define STRUCT_UNION_SPEC_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  SUS_STRUCT,
  SUS_UNION
} sus_kind_t;

typedef struct struct_union_spec
{
  sus_kind_t kind;
  const char *tag;              /* NULL if no tag */
  int n_struct_decl;            /* may be zero only if tag is non-NULL */
  struct struct_decl **struct_decls;    /* may be NULL only if tag is non-NULL */
  ast_node_t *node;
} struct_union_spec_t;

#endif
