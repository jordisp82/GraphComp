#include <assert.h>
#include <stdlib.h>

#include "struct_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct struct_declaration *
struct_declaration_1 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declaration *buff =
    calloc (1, sizeof (struct struct_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION;
  buff->sql = ptr;
#if 0
  buff->sql->parent_kind = NODE_STRUCT_DECLARATION;
  buff->sql->parent = buff;
#endif

  return buff;
}

struct struct_declaration *
struct_declaration_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_declaration *buff =
    calloc (1, sizeof (struct struct_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION;
  buff->sql = ptr1;
  buff->sdl = ptr2;
#if 0
  buff->sql->parent_kind = buff->sdl->parent_kind = NODE_STRUCT_DECLARATION;
  buff->sql->parent = buff->sdl->parent = buff;
#endif

  return buff;
}

struct struct_declaration *
struct_declaration_3 (void *ptr)
{
  assert (ptr != NULL);

  struct struct_declaration *buff =
    calloc (1, sizeof (struct struct_declaration));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_DECLARATION;
  buff->sad = ptr;
#if 0
  buff->sad->parent_kind = NODE_STRUCT_DECLARATION;
  buff->sad->parent = buff;
#endif

  return buff;
}
