#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "struct_or_union_specifier.h"
#include "struct_or_union.h"
#include "struct_declaration_list.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct struct_or_union_specifier *
struct_or_union_specifier_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct struct_or_union_specifier *buff =
    calloc (1, sizeof (struct struct_or_union_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su = ptr1;
  buff->sdl = ptr2;
  buff->su->parent_kind = buff->sdl->parent_kind =
    NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su->parent = buff->sdl->parent = buff;

  return buff;
}

struct struct_or_union_specifier *
struct_or_union_specifier_2 (void *ptr1, const char *str, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (str != NULL);
  assert (ptr3 != NULL);

  struct struct_or_union_specifier *buff =
    calloc (1, sizeof (struct struct_or_union_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su = ptr1;
  buff->sdl = ptr3;
  buff->tag = strdup (str);
  assert (buff->tag != NULL);
  buff->su->parent_kind = buff->sdl->parent_kind =
    NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su->parent = buff->sdl->parent = buff;

  return buff;
}

struct struct_or_union_specifier *
struct_or_union_specifier_3 (void *ptr1, const char *str)
{
  assert (ptr1 != NULL);
  assert (str != NULL);

  struct struct_or_union_specifier *buff =
    calloc (1, sizeof (struct struct_or_union_specifier));
  assert (buff != NULL);
  buff->kind = NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su = ptr1;
  buff->tag = strdup (str);
  assert (buff->tag != NULL);
  buff->su->parent_kind = NODE_STRUCT_OR_UNION_SPECIFIER;
  buff->su->parent = buff;

  return buff;
}

symbol_t *
create_symbol_from_sus (struct struct_or_union_specifier *buff)
{
  assert (buff != NULL);

  if (buff->tag == NULL)
    return NULL;

  symbol_t *sym = calloc (1, sizeof (symbol_t));
  assert (sym != NULL);

  sym->name = buff->tag;
  sym->sym_ns = SYM_NS_TAG;
  sym->sus = buff;
  sym->tag_kind = NODE_STRUCT_OR_UNION_SPECIFIER;
  /* the other fields to be filled in by callers */

  return sym;
}
