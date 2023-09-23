#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "dot_create.h"
#include "structs.h"
#include "node_kind_t.h"
#include "translation_unit.h"
#include "external_declaration.h"
#include "function_definition.h"
#include "declaration.h"
#include "declaration_specifiers.h"
#include "init_declarator_list.h"
#include "static_assert_declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

int
dot_create (struct translation_unit *tu, const char *fname)
{
  assert (tu != NULL);
  assert (fname != NULL);
  assert (tu->kind == NODE_TRANSLATION_UNIT);

  FILE *f = fopen (fname, "w");
  if (f == NULL)
    {
      fprintf (stderr, "[%s:%d]<%s> '%s': %s (errno %d)\n", __FILE__,
               __LINE__, __func__, fname, strerror (errno), errno);
      return -1;
    }

  tu->dot_create (tu, f);
  fclose (f);
  return 0;
}
