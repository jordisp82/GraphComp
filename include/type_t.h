#ifndef TYPE_T_H
#define TYPE_T_H

struct type_s;

/* NOTE
 * Strictly speaking, an enum is not a derived type,
 * but it's more complex than the other non-derived
 * types.
 */
typedef enum
{
  TYPE_UNKNOWN = 0,
  TYPE_NO_DERIVED,
  TYPE_ARRAY,
  TYPE_STRUCT,
  TYPE_UNION,
  TYPE_ENUM,
  TYPE_FUNCTION,
  TYPE_POINTER,
  TYPE_ATOMIC,
  TYPE_TYPEDEF
} type_kind_t;

typedef enum
{
  QUAL_NONE = 0,
  QUAL_CONST = 0x01,
  QUAL_VOLATILE = 0x02,
  QUAL_RESTRICT = 0x04
} type_qual_t;

/*
 * Native scalar types that are not derived,
 * arithmetic with void.
 */
typedef enum
{
  NT_UNKNOWN = 0,
  NT_VOID,
  NT_CHAR,
  NT_SIGNED_CHAR,
  NT_UNSIGNED_CHAR,
  NT_SIGNED_SHORT,              /* actually signed short int */
  NT_UNSIGNED_SHORT,            /* actually unsigned short int */
  NT_SIGNED_INT,
  NT_UNSIGNED_INT,
  NT_SIGNED_LONG,               /* actually signed long int */
  NT_UNSIGNED_LONG,             /* actually unsigned long int */
  NT_SIGNED_LONG_LONG,          /* actually signed long long int */
  NT_UNSIGNED_LONG_LONG,        /* actually unsigned long long int */
  NT_FLOAT,
  NT_DOUBLE,
  NT_LONG_DOUBLE,
  NT_BOOL,
  NT_FLOAT_COMPLEX,
  NT_DOUBLE_COMPLEX,
  NT_LONG_DOUBLE_COMPLEX
} nd_type_t;

typedef struct
{
  int n_cells;                  /* number of elements in the array, 0 if FAM */
  struct type_s *cell_type;     /* type of each element in the array */
} array_type_t;

typedef struct
{
  const char *name;             /* name in the declarator */
  struct type_s *can_type;      /* canonical type */
} typedef_type_t;

typedef struct
{
  struct type_s *type;          /* mandatory */
  const char *name;             /* mandatory if bits is zero */
  int bits;                     /* mandatory (not zero) is name is NULL */
} field_type_t;

typedef struct
{
  const char *tag;              /* may be NULL */
  int n_fields;                 /* greater than zero */
  field_type_t **fields;
  int fam;                      /* 1 if it has a flexible array member */
} struct_type_t;

typedef struct
{
  const char *tag;              /* may be NULL */
  int n_fields;                 /* greater than zero */
  field_type_t **fields;
  int fam;                      /* 1 if it has a flexible array member */
} union_type_t;

typedef struct type_s
{
  type_kind_t type_kind;
  type_qual_t type_quals;
  union
  {
    nd_type_t nd_type;          /* TYPE_NO_DERIVED */
    array_type_t array_type;    /* TYPE_ARRAY */
    struct_type_t struct_type;  /* TYPE_STRUCT */
    union_type_t union_type;    /* TYPE_UNION */
    struct type_s *ptr_type;    /* TYPE_POINTER */
    /* NOTE atomic? */
    typedef_type_t typedef_type;        /* TYPE_TYPEDEF */
  };
} type_t;

#endif
