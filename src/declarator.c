#include <assert.h>
#include <stdlib.h>

#include "declarator.h"
#include "pointer.h"
#include "direct_declarator.h"

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

symbol_t *
create_symbol_for_declarator (struct declarator *buff)
{
  assert (buff);
  assert (buff->kind == NODE_DECLARATOR);

  return create_symbol_for_direct_declarator (buff->ddclr);
}

int
create_symbols_for_parameters (struct declarator *buff, symbol_t *** sym_pars)
{
  assert (buff != NULL);
  assert (sym_pars != NULL);
  assert (buff->kind == NODE_DECLARATOR);

  return create_symbols_for_func_pars (buff->ddclr, sym_pars);
}
