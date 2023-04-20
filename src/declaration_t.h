#ifndef DECLARATION_T_H
#define DECLARATION_T_H

#include "ast_t.h"

typedef struct
{
  int n_typedef;
  int n_extern;
  int n_static;
  int n_thread_local;
  int n_auto;
  int n_register;
} stg_class_spec_t;

typedef struct
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
  int n_atomic;
  int n_struct;
  int n_union;
  int n_enum;
  int n_typedef;
} type_spec_t;

typedef struct
{
  int n_const;
  int n_restrict;
  int n_volatile;
  int n_atomic;
} type_qual_t;

typedef struct
{
  int n_inline;
  int n_noreturn;
} func_spec_t;

typedef struct
{
  stg_class_spec_t stg_class_spec;
  type_spec_t type_spec;
  type_qual_t type_qual;
  func_spec_t func_spec;
} decl_specs_t;

typedef struct __enumconst
{
  const char *name;
  ast_node_t *value;
  struct __enumconst *next;
} enum_const_t;

typedef struct
{
  const char *tag;
  enum_const_t *enum_consts;
} enum_t;

#endif
