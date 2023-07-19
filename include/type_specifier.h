#ifndef TYPE_SPECIFIER_H
#define TYPE_SPECIFIER_H

/**
 * type-specifier:
 *      VOID
 *      CHAR
 *      SHORT
 *      INT
 *      LONG
 *      FLOAT
 *      DOUBLE
 *      SIGNED
 *      UNSIGNED
 *      BOOL
 *      COMPLEX
 *      IMAGINARY
 *      atomic-type-specifier
 *      struct-or-union-specifier
 *      enum-specifier
 *      TYPEDEF_NAME
 * 
 * parents:
 *      declaration-specifiers (3)(4)
 *      specifier-qualifier-list (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symbol.h"
#include "symtable.h"

typedef enum
{
  TS_VOID,
  TS_CHAR,
  TS_SHORT,
  TS_INT,
  TS_LONG,
  TS_FLOAT,
  TS_DOUBLE,
  TS_SIGNED,
  TS_UNSIGNED,
  TS_BOOL,
  TS_COMPLEX,
  TS_IMAGINARY,
  TS_ATOMIC,
  TS_STRUCT_UNION,
  TS_ENUM,
  TS_TYPEDEF
} ts_kind_t;

struct type_specifier
{
  node_kind_t kind;
  ts_kind_t ts_kind;
  union
  {
    struct atomic_type_specifier *ats;
    struct struct_or_union_specifier *sus;
    struct enum_specifier *es;
    const char *typedef_name;
  };
  struct symtable *sym_table;
  void (*create_symtable) (struct type_specifier * buff);
  struct symbol *sym;
  void (*create_symbol) (struct type_specifier * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
