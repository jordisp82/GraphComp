#ifndef FUNC_SPEC_T_H
#define FUNC_SPEC_T_H

typedef struct func_spec
{
  int n_inline;
  int n_noreturn;
  /* NOTE no ast_node_t * node */
} func_spec_t;

#endif
