#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>

#include "decl_aux.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

void
add_stg_class_spec (decl_specs_t * dst, const stg_class_spec_t * src)
{
  assert (dst != NULL);
  assert (src != NULL);

  dst->stg_class_spec.n_auto += src->n_auto;
  dst->stg_class_spec.n_extern += src->n_extern;
  dst->stg_class_spec.n_register += src->n_register;
  dst->stg_class_spec.n_static += src->n_static;
  dst->stg_class_spec.n_thread_local += src->n_thread_local;
  dst->stg_class_spec.n_typedef += src->n_typedef;
}

void
add_type_spec (decl_specs_t * dst, const type_spec_t * src)
{
  assert (dst != NULL);
  assert (src != NULL);

  dst->type_spec.n_atomic += src->n_atomic;
  dst->type_spec.n_bool += src->n_bool;
  dst->type_spec.n_char += src->n_char;
  dst->type_spec.n_complex += src->n_complex;
  dst->type_spec.n_double += src->n_double;
  dst->type_spec.n_enum += src->n_enum;
  dst->type_spec.n_float += src->n_float;
  dst->type_spec.n_imaginary += src->n_imaginary;
  dst->type_spec.n_int += src->n_int;
  dst->type_spec.n_long += src->n_long;
  dst->type_spec.n_short += src->n_short;
  dst->type_spec.n_signed += src->n_signed;
  dst->type_spec.n_struct += src->n_struct;
  dst->type_spec.n_typedef += src->n_typedef;
  dst->type_spec.n_union += src->n_union;
  dst->type_spec.n_unsigned += src->n_unsigned;
  dst->type_spec.n_void += src->n_void;
}

void
add_type_qual (decl_specs_t * dst, const type_qual_t * src)
{
  assert (dst != NULL);
  assert (src != NULL);

  dst->type_qual.n_atomic += src->n_atomic;
  dst->type_qual.n_const += src->n_const;
  dst->type_qual.n_restrict += src->n_restrict;
  dst->type_qual.n_volatile += src->n_volatile;
}

void
add_func_spec (decl_specs_t * dst, const func_spec_t * src)
{
  assert (dst != NULL);
  assert (src != NULL);

  dst->func_spec.n_inline += src->n_inline;
  dst->func_spec.n_noreturn += src->n_noreturn;
}

void
add_decl_specs (decl_specs_t * dst, const decl_specs_t * src)
{
  assert (dst != NULL);
  assert (src != NULL);

  add_stg_class_spec (dst, &src->stg_class_spec);
  add_type_spec (dst, &src->type_spec);
  add_type_qual (dst, &src->type_qual);
  add_func_spec (dst, &src->func_spec);
}

#if 0
void
add_stg_class_spec (stg_class_spec_t * dst, const stg_class_spec_t * src)
{
  assert (dst != NULL);
  assert (src != NULL);

  dst->n_auto += src->n_auto;
  dst->n_extern += src->n_extern;
  dst->n_register += src->n_register;
  dst->n_static += src->n_static;
  dst->n_thread_local += src->n_thread_local;
  dst->n_typedef += src->n_typedef;
}

void
add_type_spec (type_spec_t * dst, const type_spec_t * src)
{
  assert (dst != NULL);
  assert (src != NULL);

  dst->n_atomic += src->n_atomic;
  dst->n_bool += src->n_bool;
  dst->n_char += src->n_char;
  dst->n_complex += src->n_complex;
  dst->n_double += src->n_double;
  dst->n_enum += src->n_enum;
  dst->n_float += src->n_float;
  dst->n_imaginary += src->n_imaginary;
  dst->n_int += src->n_int;
  dst->n_long += src->n_long;
  dst->n_short += src->n_short;
  dst->n_signed += src->n_signed;
  dst->n_struct += src->n_struct;
  dst->n_typedef += src->n_typedef;
  dst->n_union += src->n_union;
  dst->n_unsigned += src->n_unsigned;
  dst->n_void += src->n_void;
}

void
add_type_qual (type_qual_t * dst, const type_qual_t * src)
{
  assert (dst != NULL);
  assert (src != NULL);

  dst->n_atomic += src->n_atomic;
  dst->n_const += src->n_const;
  dst->n_restrict += src->n_restrict;
  dst->n_volatile += src->n_volatile;
}

void
add_func_spec (func_spec_t * dst, const func_spec_t * src)
{
  assert (dst != NULL);
  assert (src != NULL);

  dst->n_inline += src->n_inline;
  dst->n_noreturn += src->n_noreturn;
}
#endif

void
debug_decl_specs (const decl_specs_t * ptr)
{
  assert (ptr != NULL);
  printf ("Storage class:\n");
  printf ("\tauto: %d\n", ptr->stg_class_spec.n_auto);
  printf ("\textern: %d\n", ptr->stg_class_spec.n_extern);
  printf ("\tregister: %d\n", ptr->stg_class_spec.n_register);
  printf ("\tstatic: %d\n", ptr->stg_class_spec.n_static);
  printf ("\tthread_local: %d\n", ptr->stg_class_spec.n_thread_local);
  printf ("\ttypedef: %d\n", ptr->stg_class_spec.n_typedef);
  printf ("Type specifier:\n");
  printf ("\tatomic: %d\n", ptr->type_spec.n_atomic);
  printf ("\tbool: %d\n", ptr->type_spec.n_bool);
  printf ("\tchar: %d\n", ptr->type_spec.n_char);
  printf ("\tcomplex: %d\n", ptr->type_spec.n_complex);
  printf ("\tdouble: %d\n", ptr->type_spec.n_double);
  printf ("\tenum: %d\n", ptr->type_spec.n_enum);
  printf ("\tfloat: %d\n", ptr->type_spec.n_float);
  printf ("\timaginary: %d\n", ptr->type_spec.n_imaginary);
  printf ("\tint: %d\n", ptr->type_spec.n_int);
  printf ("\tlong: %d\n", ptr->type_spec.n_long);
  printf ("\tshort: %d\n", ptr->type_spec.n_short);
  printf ("\tsigned: %d\n", ptr->type_spec.n_signed);
  printf ("\tstruct: %d\n", ptr->type_spec.n_struct);
  printf ("\ttypedef: %d\n", ptr->type_spec.n_typedef);
  printf ("\tunion: %d\n", ptr->type_spec.n_union);
  printf ("\tunsigned: %d\n", ptr->type_spec.n_unsigned);
  printf ("\tvoid: %d\n", ptr->type_spec.n_void);
  printf ("Type qualifier:\n");
  printf ("\tatomic: %d\n", ptr->type_qual.n_atomic);
  printf ("\tconst: %d\n", ptr->type_qual.n_const);
  printf ("\trestrict: %d\n", ptr->type_qual.n_restrict);
  printf ("\tvolatile: %d\n", ptr->type_qual.n_volatile);
  printf ("Function specifier:\n");
  printf ("\tinline: %d\n", ptr->func_spec.n_inline);
  printf ("\tnoreturn: %d\n", ptr->func_spec.n_noreturn);
}
