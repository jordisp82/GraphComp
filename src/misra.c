#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>

#include "misra.h"
#include "misra_5_3.h"
#include "misra_5_6.h"
#include "structs.h"
#include "node_kind_t.h"
#include "translation_unit.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

void
check_misra (struct translation_unit *tu)
{
  assert (tu != NULL);
  assert (tu->kind == NODE_TRANSLATION_UNIT);

  /* NOTE rule 5.1 is low priority,
     and it encompasses several files */
  /* NOTE rule 5.2 is low priority */
  check_misra_5_3 (tu->sym_table);
  /* NOTE rule 5.4 involves macros */
  /* NOTE rule 5.5 involves macros */
  check_misra_5_6 (tu->sym_table);
}
