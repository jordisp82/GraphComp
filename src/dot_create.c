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

  fprintf (f, "digraph tu {\n");
  for (struct tu_node * ptr = tu->first; ptr != NULL; ptr = ptr->next)
    {
      fprintf (f, "\ttu [label=\"translation unit\"]\n");
      fprintf (f, "\ttu -> %x;\n", ptr->ed);
      fprintf (f, "\t%x [label=\"external declaration\"]\n", ptr->ed);
    }

  /* TODO */

  fprintf (f, "}\n");
  fclose (f);
  return 0;
}
