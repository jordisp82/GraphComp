#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "function_specifier.h"
#include "declaration_specifiers.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
static void do_term (struct function_specifier *node, FILE * f,
                     const char *token, int n_token);

struct function_specifier *
function_specifier_1 (void)
{
  struct function_specifier *buff =
    calloc (1, sizeof (struct function_specifier));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_SPECIFIER;
  buff->fs_kind = FS_INLINE;

  buff->dot_create = local_dot_create;

  return buff;
}

struct function_specifier *
function_specifier_2 (void)
{
  struct function_specifier *buff =
    calloc (1, sizeof (struct function_specifier));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_SPECIFIER;
  buff->fs_kind = FS_NORETURN;

  buff->dot_create = local_dot_create;

  return buff;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct function_specifier *node = Node;
  assert (node->kind == NODE_FUNCTION_SPECIFIER);
  FILE *f = F;

  switch (node->fs_kind)
    {
    case FS_INLINE:
      do_term (node, f, "inline", 0);
      break;

    case FS_NORETURN:
      do_term (node, f, "_Noreturn", 0);
      break;

    default:;                  /* BUG! */
    }
}

static void
do_term (struct function_specifier *node, FILE * f, const char *token,
         int n_token)
{
  assert (node != NULL);
  assert (f != NULL);
  assert (token != NULL);
  assert (n_token >= 0);

  fprintf (f, "\t%lu -> %lu%d;\n", (unsigned long) node,
           (unsigned long) node, n_token);
  fprintf (f, "\t%lu%d [label=\"%s\",shape=box,fontname=Courier]\n",
           (unsigned long) node, n_token, token);
}
