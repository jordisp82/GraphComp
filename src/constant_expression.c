#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "constant_expression.h"
#include "conditional_expression.h"
#include "labeled_statement.h"
#include "static_assert_declaration.h"
#include "alignment_specifier.h"
#include "struct_declarator.h"
#include "enumerator.h"
#include "designator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct constant_expression *
constant_expression_1 (void *ptr)
{
  assert (ptr != NULL);

  struct constant_expression *buff =
    calloc (1, sizeof (struct constant_expression));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT_EXPRESSION;
  buff->expr = ptr;
  buff->expr->parent_kind = NODE_CONSTANT_EXPRESSION;
  buff->expr->parent = buff;

  return buff;
}
