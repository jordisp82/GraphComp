#ifndef C_TYPE_H
#define C_TYPE_H

struct c_type;
struct c_type_object;
struct c_type_function;

typedef enum {
    TYPE_COMPLETE,
    TYPE_INCOMPLETE
} type_size_t;

typedef enum {
    TYPE_VOID,
    TYPE_ARITHMETIC,
    TYPE_ENUM,
    TYPE_DERIVED,
} type_kind_t;

typedef enum {
    TYPE_DERIVED_ARRAY,
    TYPE_DERIVED_STRUCT,
    TYPE_DERIVED_UNION,
    TYPE_DERIVED_FUNCTION,
    TYPE_DERIVED_POINTER,
    TYPE_DERIVED_ATOMIC
} type_derived_kind_t;

typedef enum
{
    TYPE_BOOL,
    TYPE_CHAR,
    TYPE_SIGNED_CHAR,
    TYPE_UNSIGNED_CHAR,
    TYPE_SIGNED_SHORT,
    TYPE_UNSIGNED_SHORT,
    TYPE_SIGNED_INT,
    TYPE_UNSIGNED_INT,
    TYPE_SIGNED_LONG,
    TYPE_UNSIGNED_LONG,
    TYPE_SIGNED_LONG_LONG,
    TYPE_UNSIGNED_LONG_LONG,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_LONG_DOUBLE,
    TYPE_FLOAT_COMPLEX,
    TYPE_DOUBLE_COMPLEX,
    TYPE_LONG_DOUBLE_COMPLEX
} type_arithmetic_t;

typedef enum {
    TYPE_QUAL_CONST = 0x1,
    TYPE_QUAL_VOLATILE = 0x2,
    TYPE_QUAL_RESTRICT = 0x4 /* only for pointers */
} type_qual_t;

typedef struct c_type
{
    type_kind_t type_kind;
    type_size_t type_size;
    union
    {
        type_arithmetic_t type_arith;   /* for TYPE_ARITHMETIC */
        type_derived_kind_t type_derived;   /* for TYPE_DERIVED */
        /* TODO TYPE_ENUM */
    };
    /* TODO tipus derivats */
    int qualifiers;
} type_t;

typedef struct c_type_object
{
} type_object_t;

typedef struct c_type_function
{
} type_function_t;

#endif
