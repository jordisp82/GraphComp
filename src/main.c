#include <assert.h>
#include <stdio.h>

#include "grammar.tab.h"
#include "ast.h"
#include "symtable.h"

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

  sym_node_t *symtable = create_symtable (ast);
  assert (symtable != NULL);
}
