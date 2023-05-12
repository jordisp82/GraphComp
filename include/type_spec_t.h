#ifndef TYPE_SPEC_T_H
#define TYPE_SPEC_T_H

#include "ast_t.h"
#include "structs_t.h"

typedef struct type_spec
{
  int n_void;
  int n_char;
  int n_short;
  int n_int;
  int n_long;
  int n_float;
  int n_double;
  int n_signed;
  int n_unsigned;
  int n_bool;
  int n_complex;
  int n_imaginary;              /* extension */
  /* NOTE fuck off atomic */
  struct struct_union_spec *struct_or_union;
  struct enum_spec *enum_spec;
  ast_node_t *node;
} type_spec_t;

#endif
