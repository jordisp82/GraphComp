#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "declarator.h"
#include "pointer.h"
#include "direct_declarator.h"
#include "init_declarator.h"
#include "struct_declarator.h"
#include "direct_declarator.h"
#include "parameter_declaration.h"
#include "function_definition.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct declarator *
declarator_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declarator *buff = calloc (1, sizeof (struct declarator));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATOR;
  buff->dclr_kind = DCLR_WITH_POINTER;
  buff->ptr = ptr1;
  buff->ddclr = ptr2;
  buff->ptr->parent_kind = buff->ddclr->parent_kind = NODE_DECLARATOR;
  buff->ptr->parent = buff->ddclr->parent = buff;

  return buff;
}

struct declarator *
declarator_2 (void *ptr)
{
  assert (ptr != NULL);

  struct declarator *buff = calloc (1, sizeof (struct declarator));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATOR;
  buff->dclr_kind = DCLR_NO_POINTER;
  buff->ddclr = ptr;
  buff->ddclr->parent_kind = NODE_DECLARATOR;
  buff->ddclr->parent = buff;

  return buff;
}
