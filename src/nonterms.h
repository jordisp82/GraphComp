#ifndef NONTERMS_H
#define NONTERMS_H

struct __tu;
struct __extdef;
struct __funcdef;
struct __decl;
struct __declspecs;
struct __declr;
struct __decllist;
struct __compstmt;
struct __stgclasspec;
struct __typespec;
struct __typequal;
struct __funcspec;
struct __alignspec;
struct __pointer;
struct __ddeclr;
struct __ptlist;
struct __paramdecl;

typedef enum
{
  EXTDEF_FUNC_DEF,
  EXTDEF_DECL
} ext_def_kind_t;

typedef struct __tu
{
  int n_children;
  struct __extdef **children;
} tu_t;

typedef struct __extdef
{
  ext_def_kind_t kind;
  union
  {
    struct __funcdef *funcdef;
    struct __decl *decl;
  } child;
} ext_def_t;

typedef struct __funcdef
{
  struct __declspecs *decl_specs;
  struct __declr *declarator;
  struct __decllist *decl_list; /* only for K&R-style */
  struct __compstmt *compound_stmt;
} func_def_t;

typedef struct __decllist
{
  int n_children;
  struct __decl **children;
} decl_list_t;

typedef struct __stgclasspec
{
  int n_typedef;
  int n_extern;
  int n_static;
  int n_thread_local;
  int n_auto;
  int n_register;
} stg_class_spec_t;

typedef struct __typespec
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

typedef struct __typequal
{
  int n_const;
  int n_restrict;
  int n_volatile;
  int n_atomic;
} type_qual_t;

typedef struct __funcspec
{
  int n_inline;
  int n_noreturn;
} func_spec_t;

typedef struct __declspecs
{
  stg_class_spec_t stg_class;
  type_spec_t type_spec;
  type_qual_t type_qual;
  func_spec_t func_spec;
  //struct __alignspec **align_spec;
} decl_specs_t;

typedef struct __declr
{
  int n_pointers;
  struct __pointer **pointers;
  struct __ddeclr *dir_declr;
} declarator_t;

typedef struct __pointer
{
  type_qual_t type_qual;
} pointer_t;

typedef enum
{
  DIR_DECLR_IDENT,
  DIR_DECLR_DECLR,
  DIR_DECLR_ARRAY,
  DIR_DECLR_FUNCTION
} dir_declr_kind_t;

typedef struct
{
  const char *id;
} dir_declr_ident_t;

typedef struct
{
  declarator_t *declr;
} dir_declr_declr_t;

typedef struct
{
  struct __ddeclr *ddeclr;
  /* TODO */
} dir_declr_array_t;

typedef struct
{
  struct __ddeclr *ddeclr;
  struct __ptlist *ptlist;
} dir_declr_function_t;

typedef struct __ddeclr
{
  dir_declr_kind_t kind;
  union
  {
    dir_declr_ident_t ident;
    declarator_t *declr;
    dir_declr_array_t array;
    dir_declr_function_t function;
  } ddeclr;
} direct_declr_t;

typedef struct __ptlist
{
  int is_variadic;
  int n_params;
  struct __paramdecl **params;
} param_type_list_t;

typedef struct __paramdecl
{
  decl_specs_t *decl_specs;     /* shall not be NULL */
  declarator_t *declr;          /* may be NULL */
  /* TODO abstract declarator *//* may be NULL */
} param_decl_t;

#endif
