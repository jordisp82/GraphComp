#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>

#include "grammar.tab.h"
#include "ast.h"
#include "semantic.h"

extern FILE *yyin;

int
main (int argc, char *argv[])
{
  if (argc < 2)
    return -1;

  yyin = fopen (argv[1], "r");
  if (yyin == NULL)
    return -1;

  ast_node_t *ast = NULL;

  yyparse ((void **) &ast);
  semantic_analysis (ast);

#if 0
  sym_node_t *symtable = create_symtable (ast);
  assert (symtable != NULL);
#endif
}
