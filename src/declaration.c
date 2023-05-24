#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "declaration.h"
#include "declaration_specifiers.h"
#include "init_declarator_list.h"
#include "static_assert_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct declaration *
declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr;
  buff->ds->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff;

  return buff;
}

struct declaration *
declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->ds = ptr1;
  buff->idl = ptr2;
  buff->ds->parent_kind = buff->idl->parent_kind = NODE_DECLARATION;
  buff->ds->parent = buff->idl->parent = buff;

  if (look_for_typedef (buff->ds) == 1)
    register_ids_as_typedef (buff->idl);

  return buff;
}

struct declaration *
declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration *buff = calloc (1, sizeof (struct declaration));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION;
  buff->sad = ptr;
  buff->sad->parent_kind = NODE_DECLARATION;
  buff->sad->parent = buff;

  return buff;
}

void
sem_declaration (struct declaration *buff)
{
  assert (buff != NULL);
}
