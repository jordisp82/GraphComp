#ifndef STG_CLASS_SPEC_T_H
#define STG_CLASS_SPEC_T_H

typedef struct stg_class_spec
{
  int n_typedef;
  int n_extern;
  int n_static;
  int n_thread_local;
  int n_auto;
  int n_register;
  /* NOTE no ast_node_t * node */
} stg_class_spec_t;

#endif
