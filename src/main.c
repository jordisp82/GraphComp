#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>

#include "grammar.tab.h"
#include "ast.h"
#include "structs.h"
#include "translation_unit.h"

extern FILE *yyin;

int
main (int argc, char *argv[])
{
  if (argc < 2)
    return -1;

  yyin = fopen (argv[1], "r");
  if (yyin == NULL)
    return -1;

  struct translation_unit *ast = NULL;

  yyparse ((void **) &ast);
  create_symbol_table_file (ast);
}
