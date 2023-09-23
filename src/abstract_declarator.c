#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "abstract_declarator.h"
#include "pointer.h"
#include "direct_abstract_declarator.h"
#include "parameter_declaration.h"
#include "type_name.h"
#include "direct_abstract_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct abstract_declarator *
abstract_declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct abstract_declarator *buff =
    calloc (1, sizeof (struct abstract_declarator));
  assert (buff != NULL);
  buff->kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr = ptr1;
  buff->dad = ptr2;
  buff->ptr->parent_kind = buff->dad->parent_kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr->parent = buff->dad->parent = buff;

  return buff;
}

struct abstract_declarator *
abstract_declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct abstract_declarator *buff =
    calloc (1, sizeof (struct abstract_declarator));
  assert (buff != NULL);
  buff->kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr = ptr;
  buff->ptr->parent_kind = NODE_ABSTRACT_DECLARATOR;
  buff->ptr->parent = buff;

  return buff;
}

struct abstract_declarator *
abstract_declarator_3 (void *ptr)
{
  assert (ptr != NULL);

  struct abstract_declarator *buff =
    calloc (1, sizeof (struct abstract_declarator));
  assert (buff != NULL);
  buff->kind = NODE_ABSTRACT_DECLARATOR;
  buff->dad = ptr;
  buff->dad->parent_kind = NODE_ABSTRACT_DECLARATOR;
  buff->dad->parent = buff;

  return buff;
}

