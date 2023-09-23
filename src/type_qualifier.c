#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "type_qualifier.h"
#include "declaration_specifiers.h"
#include "specifier_qualifier_list.h"
#include "type_qualifier_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct type_qualifier *
type_qualifier_1 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_CONST;

  return buff;
}

struct type_qualifier *
type_qualifier_2 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_RESTRICT;

  return buff;
}

struct type_qualifier *
type_qualifier_3 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_VOLATILE;

  return buff;
}

struct type_qualifier *
type_qualifier_4 (void)
{
  struct type_qualifier *buff = calloc (1, sizeof (struct type_qualifier));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_QUALIFIER;
  buff->tq_kind = TQ_ATOMIC;

  return buff;
}
