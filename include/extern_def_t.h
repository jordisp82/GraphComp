#ifndef EXTERN_DEF_T_H
#define EXTERN_DEF_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef enum
{
  EXTDEF_FUNC_DEF,
  EXTDEF_DECL
} ext_def_kind_t;

typedef struct extern_def
{
  ext_def_kind_t kind;
  union
  {
    struct func_def *func_def;
    struct decltion *decltion;
  };
  ast_node_t *node;
} extern_def_t;

#endif
