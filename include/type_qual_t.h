#ifndef TYPE_QUAL_T_H
#define TYPE_QUAL_T_H

typedef struct type_qual
{
  int n_const;
  int n_restrict;
  int n_volatile;
  int n_atomic;
  /* NOTE no ast_node_t * node */
} type_qual_t;

#endif
