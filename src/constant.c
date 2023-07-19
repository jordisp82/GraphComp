#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "constant.h"
#include "primary_expression.h"
#include "avl_tree.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void c_create_symtable (struct constant *buff);
static void c_create_symbol (struct constant *buff);

struct constant *
constant_1 (int value)
{
  struct constant *buff = calloc (1, sizeof (struct constant));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT;
  buff->const_kind = CONST_INTEGER;
  buff->integer = value;
  buff->create_symtable = c_create_symtable;
  buff->create_symbol = c_create_symbol;

  return buff;
}

struct constant *
constant_2 (double value)
{
  struct constant *buff = calloc (1, sizeof (struct constant));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT;
  buff->const_kind = CONST_FLOAT;
  buff->floating = value;
  buff->create_symtable = c_create_symtable;
  buff->create_symbol = c_create_symbol;

  return buff;
}

struct constant *
constant_3 (const char *str)
{
  assert (str != NULL);

  struct constant *buff = calloc (1, sizeof (struct constant));
  assert (buff != NULL);
  buff->kind = NODE_CONSTANT;
  buff->const_kind = CONST_ENUM;
  buff->string = strdup (str);
  assert (buff->string != NULL);
  buff->create_symtable = c_create_symtable;
  buff->create_symbol = c_create_symbol;

  return buff;
}

static void
c_create_symtable (struct constant *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CONSTANT);

  buff->sym_table = ((struct primary_expression *) (buff->parent))->sym_table;
}

static void
c_create_symbol (struct constant *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_CONSTANT);
  assert (buff->sym_table != NULL);

  if (buff->const_kind == CONST_ENUM)
    {
      avl_node_t *node = avl_search (buff->sym_table->ord, buff->string);
      if (node != NULL)
        buff->sym = node->value;
    }
}
