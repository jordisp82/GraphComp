#ifndef ENUM_SPEC_T_H
#define ENUM_SPEC_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct enum_spec
{
  const char *tag;              /* if there is a tag */
  int n_enumerators;            /* may be zero */
  struct enumerator *enumerators;       /* may be NULL */
  ast_node_t *node;
} enum_spec_t;

#endif
