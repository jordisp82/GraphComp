#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>

#include "project_t.h"
#include "parse_cmd_line.h"
#include "preproc.h"
#include "grammar.tab.h"
#include "ast.h"
#include "structs.h"
#include "translation_unit.h"
#include "misra.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

extern FILE *yyin;

int
main (int argc, char *argv[])
{
  project_t project = PROJECT_ZERO;
  if (parse_cmd_line (argc, argv, &project) < 0)
    return -1;

  assert (project.files != NULL);
  for (cfile_t * ptr = project.files->next; ptr != NULL; ptr = ptr->next)
    {
      char *dst = NULL;
      if (preproc (ptr->fname, &dst, project.ipaths, project.macros) == 0)
        {
          struct translation_unit *ast = NULL;
          yyin = fopen (dst, "r");
          yyparse ((void **) &ast);
          ast->create_symtable (ast);
          check_misra (ast);
        }
    }

  return 0;
}
