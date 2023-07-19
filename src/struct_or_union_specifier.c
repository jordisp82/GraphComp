#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "struct_or_union_specifier.h"
#include "struct_or_union.h"
#include "struct_declaration_list.h"
#include "type_specifier.h"
#include "symbol.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sus_create_symtable (struct struct_or_union_specifier *buff);

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
  buff->create_symtable = sus_create_symtable;

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
  buff->create_symtable = sus_create_symtable;

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
  buff->create_symtable = sus_create_symtable;

  return buff;
}

static void
sus_create_symtable (struct struct_or_union_specifier *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_STRUCT_OR_UNION_SPECIFIER);

  buff->sym_table = ((struct type_specifier *) (buff->parent))->sym_table;
  if (buff->su != NULL)
    buff->su->create_symtable (buff->su);
  if (buff->sdl != NULL)
    buff->sdl->create_symtable (buff->sdl);

  if (buff->tag != NULL)
    {
      symbol_t *sym = calloc (1, sizeof (symbol_t));
      assert (sym != NULL);
      sym->name = strdup (buff->tag);
      sym->sym_ns = SYM_NS_TAG;
      sym->node = buff;
      sym->node_kind = NODE_STRUCT_OR_UNION_SPECIFIER;
      buff->sym_table->tags = avl_add_create (buff->sym_table->tags, sym);
    }
}
