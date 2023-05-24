#include <assert.h>

#include "semantic.h"
#include "node_kind_t.h"
#include "translation_unit.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

void
semantic_analysis (struct translation_unit *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TRANSLATION_UNIT);

  /* TODO */
}
