#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "type_specifier.h"
#include "atomic_type_specifier.h"
#include "struct_or_union_specifier.h"
#include "enum_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct type_specifier *
type_specifier_1 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_VOID;

  return buff;
}

struct type_specifier *
type_specifier_2 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_CHAR;

  return buff;
}

struct type_specifier *
type_specifier_3 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_SHORT;

  return buff;
}

struct type_specifier *
type_specifier_4 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_INT;

  return buff;
}

struct type_specifier *
type_specifier_5 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_LONG;

  return buff;
}

struct type_specifier *
type_specifier_6 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_FLOAT;

  return buff;
}

struct type_specifier *
type_specifier_7 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_DOUBLE;

  return buff;
}

struct type_specifier *
type_specifier_8 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_SIGNED;

  return buff;
}

struct type_specifier *
type_specifier_9 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_UNSIGNED;

  return buff;
}

struct type_specifier *
type_specifier_10 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_BOOL;

  return buff;
}

struct type_specifier *
type_specifier_11 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_COMPLEX;

  return buff;
}

struct type_specifier *
type_specifier_12 (void)
{
  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_IMAGINARY;

  return buff;
}

struct type_specifier *
type_specifier_13 (void *ptr)
{
  assert (ptr != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_ATOMIC;
  buff->ats = ptr;
  buff->ats->parent_kind = NODE_TYPE_SPECIFIER;
  buff->ats->parent = buff;

  return buff;
}

struct type_specifier *
type_specifier_14 (void *ptr)
{
  assert (ptr != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_STRUCT_UNION;
  buff->sus = ptr;
  buff->sus->parent_kind = NODE_TYPE_SPECIFIER;
  buff->sus->parent = buff;

  return buff;
}

struct type_specifier *
type_specifier_15 (void *ptr)
{
  assert (ptr != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_ENUM;
  buff->es = ptr;
  buff->es->parent_kind = NODE_TYPE_SPECIFIER;
  buff->es->parent = buff;

  return buff;
}

struct type_specifier *
type_specifier_16 (const char *str)
{
  assert (str != NULL);

  struct type_specifier *buff = calloc (1, sizeof (struct type_specifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_SPECIFIER;
  buff->ts_kind = TS_TYPEDEF;
  buff->typedef_name = strdup (str);
  assert (buff->typedef_name != NULL);

  return buff;
}

symbol_t *
create_symbol_from_type_specifier (struct type_specifier *buff)
{
  assert (buff != NULL);

  /*
   * NOTE this function is only called to create
   * a symbol from a struct, union or enum with
   * a tag.
   */

  switch (buff->ts_kind)
    {
    case TS_STRUCT_UNION:
      return create_symbol_from_sus (buff->sus);
      break;

    case TS_ENUM:
      return create_symbol_from_enum_specifier (buff->es);
      break;

    default:
      return NULL;
    }
}

void
sem_type_specifier (struct type_specifier *buff)
{
  assert (buff != NULL);

  /*
   * NOTE to be removed
   * TODO
   * section 6.7.2.1, clauses 2, 3, 4 and 5
   * section 6.7.2.2, clause 2
   * section 6.7.2.3, clauses 1, 2 and 3
   */

  switch (buff->ts_kind)
    {
    case TS_STRUCT_UNION:
      sem_struct_union_specifier (buff->sus);
      break;

    case TS_ENUM:
      sem_enum_specifier (buff->es);
      break;

    default:
      ;
    }
}
