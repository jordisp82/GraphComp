#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "type_name.h"
#include "specifier_qualifier_list.h"
#include "abstract_declarator.h"
#include "postfix_expression.h"
#include "unary_expression.h"
#include "cast_expression.h"
#include "atomic_type_specifier.h"
#include "alignment_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct type_name *
type_name_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_name *buff = calloc (1, sizeof (struct type_name));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_NAME;
  buff->sql = ptr1;
  buff->adlr = ptr2;
  buff->sql->parent_kind = buff->adlr->parent_kind = NODE_TYPE_NAME;
  buff->sql->parent = buff->adlr->parent = buff;

  return buff;
}

struct type_name *
type_name_2 (void *ptr)
{
  assert (ptr != NULL);

  struct type_name *buff = calloc (1, sizeof (struct type_name));
  assert (buff != NULL);
  buff->kind = NODE_TYPE_NAME;
  buff->sql = ptr;
  buff->sql->parent_kind = NODE_TYPE_NAME;
  buff->sql->parent = buff;

  return buff;
}
