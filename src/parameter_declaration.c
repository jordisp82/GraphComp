#include <assert.h>
#include <stdlib.h>

#include "parameter_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct parameter_declaration *
parameter_declaration_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct parameter_declaration *buff =
    calloc (1, sizeof (struct parameter_declaration));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_DECLARATION;
  buff->pd_kind = PD_DS_DECLR;
  buff->ds = ptr1;
  buff->dr = ptr2;
#if 0
  buff->ds->parent_kind = buff->dr->parent_kind = NODE_PARAMETER_DECLARATION;
  buff->ds->parent = buff->dr->parent = buff;
#endif

  return buff;
}

struct parameter_declaration *
parameter_declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct parameter_declaration *buff =
    calloc (1, sizeof (struct parameter_declaration));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_DECLARATION;
  buff->pd_kind = PD_DS_ABS_DECLR;
  buff->ds = ptr1;
  buff->adr = ptr2;
#if 0
  buff->ds->parent_kind = buff->adr->parent_kind = NODE_PARAMETER_DECLARATION;
  buff->ds->parent = buff->adr->parent = buff;
#endif

  return buff;
}

struct parameter_declaration *
parameter_declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct parameter_declaration *buff =
    calloc (1, sizeof (struct parameter_declaration));
  assert (buff != NULL);
  buff->kind = NODE_PARAMETER_DECLARATION;
  buff->pd_kind = PD_DS;
  buff->ds = ptr;
#if 0
  buff->ds->parent_kind = NODE_PARAMETER_DECLARATION;
  buff->ds->parent = buff;
#endif

  return buff;
}
